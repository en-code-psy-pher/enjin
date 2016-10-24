#version 330 core

#define N_POINT_LIGHTS 4

struct DirectionalLight
{
	vec3 direction;
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};

struct PointLight
{
	vec3 position;
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	float constant;
	float linear;
	float quadratic;
};

struct SpotLight
{
	vec3 position;
	vec3 direction;
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	float constant;
	float linear;
	float quadratic;
	float cutOff;
	float outerCutOff;
};

in VS_OUT {
	vec3 Normal;
	vec3 FragPos;
	vec2 TexCoords;
} fs_in;

in vec2 TexCoords;

uniform vec3 eyePos;

uniform DirectionalLight directionalLight;
uniform PointLight pointLights[N_POINT_LIGHTS];
uniform SpotLight spotLight;

out vec4 color;

vec3 CalculateDirectionalLight(DirectionalLight light, vec3 normal, vec3 viewDir);
vec3 CalculatePointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir);
vec3 CalculateSpotLight(SpotLight light, vec3 normal, vec3 fragPos, vec3 viewDir);

void main()
{
	vec3 N = normalize(fs_in.Normal);
	vec3 V = normalize(eyePos - fs_in.FragPos);
	
	vec3 result;
	
	result = CalculateDirectionalLight(directionalLight, N, V);
	
	for(int i = 0; i < N_POINT_LIGHTS; i++)
		result += CalculatePointLight(pointLights[i], N, fs_in.FragPos, V);
		
	result += CalculateSpotLight(spotLight, N, fs_in.FragPos, V);
	
	color = vec4(result, 1.0);
}

vec3 CalculateDirectionalLight(DirectionalLight light, vec3 normal, vec3 viewDir)
{
	vec3 lightDirection = normalize(-light.direction);
	
	// Diffuse pass
	float diffuse = max(dot(normal, lightDirection), 0.0);
	
	// Specular pass
	vec3 reflectDirection = reflect(-lightDirection, normal);
	float specular = pow(max(dot(viewDir, reflectDirection), 0.0), 16.0);
	
	vec3 ambientColor = light.ambient;
	vec3 diffuseColor = light.diffuse * diffuse;
	vec3 specularColor = light.specular * specular;
	
	return (ambientColor + diffuseColor + specularColor);
}

vec3 CalculatePointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir)
{
	vec3 lightDirection = normalize(light.position - fragPos);
	
	// Diffuse pass
	float diffuse = max(dot(normal, lightDirection), 0.0);
	
	// Specular pass
	vec3 reflectDirection = reflect(-lightDirection, normal);
	float specular = pow(max(dot(viewDir, reflectDirection), 0.0), 16.0f);
	
	// Attenuation
	float distance = length(light.position - fragPos);
	float attenuation = 1.0f / (light.constant + light.linear * distance + light.quadratic * (distance * distance));
	
	vec3 ambientColor = light.ambient;
	vec3 diffuseColor = light.diffuse * diffuse;
	vec3 specularColor = light.diffuse * specular;
	
	ambientColor *= attenuation;
	diffuseColor *= attenuation;
	specularColor *= attenuation;
	
	return (ambientColor + diffuseColor + specularColor);
}

vec3 CalculateSpotLight(SpotLight light, vec3 normal, vec3 fragPos, vec3 viewDir)
{
	vec3 lightDirection = normalize(light.position - fragPos);
	
	// Diffuse pass
	float diffuse = max(dot(normal, lightDirection), 0.0);
	
	// Specular pass
	vec3 reflectDirection = reflect(-lightDirection, normal);
	float specular = pow(max(dot(viewDir, reflectDirection), 0.0), 16.0f);
	
	// Attenuation
	float distance = length(light.position - fragPos);
	float attenuation = 1.0f / (light.constant + light.linear * distance + light.quadratic * (distance * distance));
	
	// Light Cutoff
	float theta = dot(lightDirection, normalize(-light.direction));
	float epsilon = light.cutOff - light.outerCutOff;
	float intensity = clamp((theta - light.outerCutOff) / epsilon, 0.0, 1.0f);
	
	vec3 ambientColor = light.ambient;
	vec3 diffuseColor = light.diffuse * diffuse;
	vec3 specularColor = light.diffuse * specular;
	
	ambientColor *= attenuation;
	diffuseColor *= attenuation;
	specularColor *= attenuation;
	
	return (ambientColor + diffuseColor + specularColor);
}
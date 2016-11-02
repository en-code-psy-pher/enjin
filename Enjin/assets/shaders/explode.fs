#version 330 core

#define N_POINT_LIGHTS 4

struct Material
{
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	float shininess;
};

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

in GS_OUT {
    vec2 texCoords;
    vec3 fragPos;
    vec3 normal;
} fs_in;

uniform vec3 _eyePos;

uniform Material _material;
uniform DirectionalLight _directionalLight;
uniform PointLight _pointLights[N_POINT_LIGHTS];
uniform SpotLight _spotLight;

out vec4 _color;

vec3 CalculateDirectionalLight(DirectionalLight light, vec3 normal, vec3 viewDir);
vec3 CalculatePointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir);
vec3 CalculateSpotLight(SpotLight light, vec3 normal, vec3 fragPos, vec3 viewDir);

void main()
{
	vec3 N = normalize(fs_in.normal);
	vec3 V = normalize(_eyePos - fs_in.fragPos);
	
	vec3 result = vec3(0.0);
	
	result = CalculateDirectionalLight(_directionalLight, N, V);
	
	for(int i = 0; i < N_POINT_LIGHTS; i++)
		result += CalculatePointLight(_pointLights[i], N, fs_in.fragPos, V);
		
	result += CalculateSpotLight(_spotLight, N, fs_in.fragPos, V);
	
	_color = vec4(result, 1.0);
}

vec3 CalculateDirectionalLight(DirectionalLight light, vec3 normal, vec3 viewDir)
{
	vec3 lightDirection = normalize(-light.direction);
	
	// Diffuse pass
	float diffuse = max(dot(normal, lightDirection), 0.0);
	
	// Specular pass
	vec3 reflectDirection = reflect(-lightDirection, normal);
	float specular = pow(max(dot(viewDir, reflectDirection), 0.0), _material.shininess);
	
	vec3 ambientColor = light.ambient * _material.ambient;
	vec3 diffuseColor = light.diffuse * (diffuse * _material.diffuse);
	vec3 specularColor = light.specular * (specular * _material.specular);
	
	return (ambientColor + diffuseColor + specularColor);
}

vec3 CalculatePointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir)
{
	vec3 lightDirection = normalize(light.position - fragPos);
	
	// Diffuse pass
	float diffuse = max(dot(normal, lightDirection), 0.0);
	
	// Specular pass
	vec3 reflectDirection = reflect(-lightDirection, normal);
	float specular = pow(max(dot(viewDir, reflectDirection), 0.0), _material.shininess);
	
	// Attenuation
	float distance = length(light.position - fragPos);
	float attenuation = 1.0f / (light.constant + light.linear * distance + light.quadratic * (distance * distance));
	
	vec3 ambientColor = light.ambient * _material.ambient;
	vec3 diffuseColor = light.diffuse * (diffuse * _material.diffuse);
	vec3 specularColor = light.diffuse * (specular * _material.specular);
	
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
	float specular = pow(max(dot(viewDir, reflectDirection), 0.0), _material.shininess);
	
	// Attenuation
	float distance = length(light.position - fragPos);
	float attenuation = 1.0f / (light.constant + light.linear * distance + light.quadratic * (distance * distance));
	
	// Light Cutoff
	float theta = dot(lightDirection, normalize(-light.direction));
	float epsilon = light.cutOff - light.outerCutOff;
	float intensity = clamp((theta - light.outerCutOff) / epsilon, 0.0, 1.0f);
	
	vec3 ambientColor = light.ambient * _material.ambient;
	vec3 diffuseColor = light.diffuse * (diffuse * _material.diffuse);
	vec3 specularColor = light.diffuse * (specular * _material.specular);
	
	ambientColor *= attenuation;
	diffuseColor *= attenuation;
	specularColor *= attenuation;
	
	return (ambientColor + diffuseColor + specularColor);
}
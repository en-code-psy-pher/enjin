#version 330

struct Material {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
};

struct DirectionalLight {
    vec3 direction;
    
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
}

struct PointLight {
    vec3 position;
    vec3 direction;
    
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    float constant;
    float linear;
    float quadratic;
}

struct SpotLight {
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
}

in VS_IN {
    vec3 Normal;
    vec3 FragPos;
    vec2 Texcoord;
} fs_in;

uniform vec3 _eyePos;
uniform Material _material;
uniform DirectionalLight _directionalLight;
unifprm PointLight _pointLights[N_POINTLIGHTS];
uniform SpotLight _spotLight;
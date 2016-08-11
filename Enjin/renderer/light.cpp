#include "light.h"

Light::Light()
	: m_ambient(vec3(1.0f)), m_diffuse(vec3(1.0f)), m_specular(vec3(1.0f))
{
}

Light::Light(vec3 ambient = vec3(0.05f), vec3 diffuse = vec3(0.4f), vec3 specular = vec3(1.0f))
	: m_ambient(ambient), m_diffuse(diffuse), m_specular(specular)
{
}

Light::~Light()
{
}

#include "directionalLight.h"

DirectionalLight::DirectionalLight() 
	: Light(vec3(1.0f), vec3(1.0f), vec3(1.0f)),
		m_direction(vec3(1.0f, 0.0f, 0.1f))
{
}

DirectionalLight::DirectionalLight(vec3 direction, vec3 ambient, vec3 diffuse, vec3 specular)
	: Light(ambient, diffuse, specular), 
			m_direction(direction)
{
}

DirectionalLight::~DirectionalLight()
{
}

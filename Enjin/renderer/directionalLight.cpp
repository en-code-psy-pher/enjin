#include "directionalLight.h"

DirectionalLight::DirectionalLight()
{
}

DirectionalLight::DirectionalLight(vec3 direction, vec3 ambient, vec3 diffuse, vec3 specular)
	: Light(ambient, diffuse, specular), 
			m_direction(direction)
{
}
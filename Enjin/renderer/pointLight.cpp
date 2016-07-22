#include "pointLight.h"

PointLight::PointLight()
{
}

PointLight::PointLight(vec3 position, float constant, float linear, float quadratic, vec3 ambient, vec3 diffuse, vec3 specular)
	: Light(ambient, diffuse, specular), 
			m_position(position), 
			m_constant(constant), m_linear(linear), m_quadratic(quadratic)
{
}
#include "pointLight.h"

PointLight::PointLight()
	: Light(vec3(1.0f), vec3(1.0f), vec3(1.0f)),
		m_position(vec3(0.0f, 10.0f, 0.0f)),
		m_constant(1.0f), m_linear(0.009f), m_quadratic(0.0032f)
{
}

PointLight::PointLight(vec3 position, float constant, float linear, float quadratic, vec3 ambient, vec3 diffuse, vec3 specular)
	: Light(ambient, diffuse, specular), 
			m_position(position), 
			m_constant(constant), m_linear(linear), m_quadratic(quadratic)
{
}

PointLight::~PointLight()
{
}

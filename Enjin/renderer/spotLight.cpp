#include "spotLight.h"

SpotLight::SpotLight()
	: Light(vec3(1.0f), vec3(1.0f), vec3(1.0f)),
		m_position(vec3(0.0f, 10.0f, 0.0f)), m_direction(vec3(0.0f, -1.0f, 0.0f)),
		m_constant(1.0f), m_linear(0.009f), m_quadratic(0.0032f)
{
	this->m_cutOff = glm::cos(glm::radians(12.5f));
	this->m_outerCutOff = glm::cos(glm::radians(15.0f));
}

SpotLight::SpotLight(vec3 position, vec3 direction, float constant, float linear, float quadratic, vec3 ambient, vec3 diffuse, vec3 specular, float cutOff, float outerCutOff)
	: Light(ambient, diffuse, specular), 
			m_position(position), m_direction(direction), 
			m_constant(constant), m_linear(linear), m_quadratic(quadratic), 
			m_cutOff(cutOff), m_outerCutOff(outerCutOff)
{
}

SpotLight::~SpotLight()
{
}

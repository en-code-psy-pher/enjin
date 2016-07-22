#include "spotLight.h"

SpotLight::SpotLight()
{
}

SpotLight::SpotLight(vec3 position, vec3 direction, float constant, float linear, float quadratic, vec3 ambient, vec3 diffuse, vec3 specular, float cutOff, float outerCutOff)
	: Light(ambient, diffuse, specular), 
			m_position(position), m_direction(direction), 
			m_constant(constant), m_linear(linear), m_quadratic(quadratic), 
			m_cutOff(cutOff), m_outerCutOff(outerCutOff)
{
}
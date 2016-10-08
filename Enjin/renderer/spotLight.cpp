#include "spotLight.h"

// Default Constructor
SpotLight::SpotLight()
	:	m_position(vec3(0.0f, 10.0f, 0.0f)), m_direction(vec3(0.0f, -1.0f, 0.0f)),
		m_constant(1.0f), m_linear(0.009f), m_quadratic(0.0032f)
{
	Light();
	this->m_cutOff = glm::cos(glm::radians(12.5f));
	this->m_outerCutOff = glm::cos(glm::radians(15.0f));
}

// Parameter Constructor
SpotLight::SpotLight(vec3 position, vec3 direction, float constant, float linear, float quadratic, vec3 ambient, vec3 diffuse, vec3 specular, float cutOff, float outerCutOff)
	:	m_position(position), m_direction(direction), m_constant(constant), m_linear(linear), m_quadratic(quadratic), 
		m_cutOff(cutOff), m_outerCutOff(outerCutOff)
{
	Light(ambient, diffuse, specular);
}

// Copy Constructor (lvalue)
SpotLight::SpotLight(const SpotLight & other)
{
	Light(other.m_ambient, other.m_diffuse, other.m_specular);
	this->m_position = other.m_position;
	this->m_direction = other.m_direction;
	this->m_constant = other.m_constant;
	this->m_linear = other.m_linear;
	this->m_quadratic = other.m_quadratic;
	this->m_cutOff = other.m_cutOff;
	this->m_outerCutOff = other.m_outerCutOff;
}

// Move Constructor (rvalue)
SpotLight::SpotLight(const SpotLight && other)
{
	Light(other.m_ambient, other.m_diffuse, other.m_specular);
	this->m_position = other.m_position;
	this->m_direction = other.m_direction;
	this->m_constant = other.m_constant;
	this->m_linear = other.m_linear;
	this->m_quadratic = other.m_quadratic;
	this->m_cutOff = other.m_cutOff;
	this->m_outerCutOff = other.m_outerCutOff;
}

// Copy Assignment (lvalue)
SpotLight & SpotLight::operator=(const SpotLight & other)
{
	if (this == &other)
		return *this;

	this->m_position = other.m_position;
	this->m_direction = other.m_direction;
	this->m_ambient = other.m_ambient;
	this->m_diffuse = other.m_diffuse;
	this->m_specular = other.m_specular;
	this->m_constant = other.m_constant;
	this->m_linear = other.m_linear;
	this->m_quadratic = other.m_quadratic;
	this->m_cutOff = other.m_cutOff;
	this->m_outerCutOff = other.m_outerCutOff;

	return *this;
}

// Move Assignment (rvalue)
SpotLight & SpotLight::operator=(const SpotLight && other)
{
	assert(this != &other);

	this->m_position = other.m_position;
	this->m_direction = other.m_direction;
	this->m_ambient = other.m_ambient;
	this->m_diffuse = other.m_diffuse;
	this->m_specular = other.m_specular;
	this->m_constant = other.m_constant;
	this->m_linear = other.m_linear;
	this->m_quadratic = other.m_quadratic;
	this->m_cutOff = other.m_cutOff;
	this->m_outerCutOff = other.m_outerCutOff;

	return *this;
}

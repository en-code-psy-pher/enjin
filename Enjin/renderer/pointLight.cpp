#include "pointLight.h"

// Default Constructor
PointLight::PointLight()
	: Light(vec3(1.0f), vec3(1.0f), vec3(1.0f)),
			m_position(vec3(0.0f, 10.0f, 0.0f)),
			m_constant(1.0f), m_linear(0.009f), m_quadratic(0.0032f)
{
}

// Parameter Constructor
PointLight::PointLight(vec3 position, float constant, float linear, float quadratic, vec3 ambient, vec3 diffuse, vec3 specular)
	: Light(ambient, diffuse, specular), 
			m_position(position), 
			m_constant(constant), m_linear(linear), m_quadratic(quadratic)
{
}

// Copy Constructor (lvalue)
PointLight::PointLight(const PointLight & other)
	: Light(other.m_ambient, other.m_diffuse, other.m_specular)
{
	this->m_position = other.m_position;
	this->m_constant = other.m_constant;
	this->m_linear = other.m_linear;
	this->m_quadratic = other.m_quadratic;
}

// Move Constructor (rvalue)
PointLight::PointLight(const PointLight && other)
	: Light(other.m_ambient, other.m_diffuse, other.m_specular)
{
	this->m_position = other.m_position;
	this->m_constant = other.m_constant;
	this->m_linear = other.m_linear;
	this->m_quadratic = other.m_quadratic;
}

// Copy Assignment (lvalue)
PointLight & PointLight::operator=(const PointLight & other)
{
	if (this == &other)
		return *this;

	this->m_position = other.m_position;
	this->m_ambient = other.m_ambient;
	this->m_diffuse = other.m_diffuse;
	this->m_specular = other.m_specular;
	this->m_constant = other.m_constant;
	this->m_linear = other.m_linear;
	this->m_quadratic = other.m_quadratic;
}

// Move Assignment (rvalue)
PointLight & PointLight::operator=(const PointLight && other)
{
	assert(this != &other);

	this->m_position = other.m_position;
	this->m_ambient = other.m_ambient;
	this->m_diffuse = other.m_diffuse;
	this->m_specular = other.m_specular;
	this->m_constant = other.m_constant;
	this->m_linear = other.m_linear;
	this->m_quadratic = other.m_quadratic;
}

#include "directionalLight.h"

// Default Constructor
DirectionalLight::DirectionalLight() 
	: Light(vec3(1.0f), vec3(1.0f), vec3(1.0f)),
	  m_direction(vec3(1.0f, 0.0f, 0.1f))
{
}

// Parameter Constructor
DirectionalLight::DirectionalLight(vec3 direction, vec3 ambient, vec3 diffuse, vec3 specular)
	: Light(ambient, diffuse, specular), 
	  m_direction(direction)
{
}

// Copy Constructor (lvalue)
DirectionalLight::DirectionalLight(const DirectionalLight & other)
	: Light(other.m_ambient, other.m_diffuse, other.m_specular)
{
	this->m_direction = other.m_direction;
}

// Move Constructor (rvalue)
DirectionalLight::DirectionalLight(const DirectionalLight && other)
	: Light(other.m_ambient, other.m_diffuse, other.m_specular)
{
	this->m_direction = other.m_direction;
}

// Copy Assignment (lvalue)
DirectionalLight & DirectionalLight::operator=(const DirectionalLight & other)
{
	if (this == &other)
		return *this;

	this->m_ambient = other.m_ambient;
	this->m_diffuse = other.m_diffuse;
	this->m_specular = other.m_specular;
	this->m_direction = other.m_direction;

	return *this;
}

// Move Assignment (rvalue)
DirectionalLight & DirectionalLight::operator=(const DirectionalLight && other)
{
	assert(this != &other);

	this->m_ambient = other.m_ambient;
	this->m_diffuse = other.m_diffuse;
	this->m_specular = other.m_specular;
	this->m_direction = other.m_direction;

	return *this;
}

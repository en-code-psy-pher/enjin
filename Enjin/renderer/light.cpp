#include "light.h"

// Default Constructor
Light::Light()
	: m_ambient(vec3(1.0f)), m_diffuse(vec3(1.0f)), m_specular(vec3(1.0f))
{
}

// Parameter Constructor
Light::Light(vec3 ambient = vec3(0.05f), vec3 diffuse = vec3(0.4f), vec3 specular = vec3(1.0f))
	: m_ambient(ambient), m_diffuse(diffuse), m_specular(specular)
{
}

// Copy Constructor (lvalue)
Light::Light(const Light & other)
{
	this->m_ambient = other.m_ambient;
	this->m_diffuse = other.m_diffuse;
	this->m_specular = other.m_specular;
}

// Move Constructor (rvalue)
Light::Light(const Light && other)
{
	this->m_ambient = other.m_ambient;
	this->m_diffuse = other.m_diffuse;
	this->m_specular = other.m_specular;
}

// Copy Assignment (lvalue)
Light & Light::operator=(const Light & other)
{
	if (this == &other)
		return *this;

	this->m_ambient = other.m_ambient;
	this->m_diffuse = other.m_diffuse;
	this->m_specular = other.m_specular;

	return *this;
}

// Move Assignment (rvalue)
Light & Light::operator=(const Light && other)
{
	assert(this != &other);

	this->m_ambient = other.m_ambient;
	this->m_diffuse = other.m_diffuse;
	this->m_specular = other.m_specular;

	return *this;
}

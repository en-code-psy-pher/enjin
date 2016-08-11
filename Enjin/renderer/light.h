#pragma once

#include "config.h"

class Light
{
public:
	// Constructor
	Light();
	Light(vec3 ambient, vec3 diffuse, vec3 specular);

	// Virutal Destructor
	virtual ~Light();

	// Inline Functions
	inline void SetAmbient(const vec3& ambient)
	{
		this->m_ambient = ambient;
	}

	inline void SetDiffuse(const vec3& diffuse)
	{
		this->m_diffuse = diffuse;
	}

	inline void SetSpecular(const vec3& specular)
	{
		this->m_specular = specular;
	}

	inline vec3 GetAmbient() const
	{
		return this->m_ambient;
	}

	inline vec3 GetDiffuse() const
	{
		return this->m_diffuse;
	}
	
	inline vec3 GetSpecular() const
	{
		return this->m_specular;
	}

protected:
	vec3	m_ambient;
	vec3	m_diffuse;
	vec3	m_specular;
};


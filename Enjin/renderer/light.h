#ifndef LIGHT_H
#define LIGHT_H

#include "config.h"

class Light
{
public:
	// Constructors

	Light();											// Default Constructor	
	Light(vec3 ambient, vec3 diffuse, vec3 specular);	// Parameter Constructor
	Light(const Light& other);							// Copy Constructor (lvalue)
	Light(const Light&& other);							// Move Constructor (rvalue)

	Light& operator=(const Light& other);				// Copy Assignment (lvalue)
	Light& operator=(const Light&& other);				// Move Assignment (rvalue)

	// Getters & Setters

	// Set Light Ambient Color
	inline void SetAmbient(const vec3& ambient)
	{
		this->m_ambient = ambient;
	}

	// Set Light Diffuse Color
	inline void SetDiffuse(const vec3& diffuse)
	{
		this->m_diffuse = diffuse;
	}

	// Set Light Specular Color
	inline void SetSpecular(const vec3& specular)
	{
		this->m_specular = specular;
	}

	// Get Light Ambient Color
	inline vec3 GetAmbient() const
	{
		return this->m_ambient;
	}

	// Get Light Diffuse Color
	inline vec3 GetDiffuse() const
	{
		return this->m_diffuse;
	}
	
	// Get Light Specular Color
	inline vec3 GetSpecular() const
	{
		return this->m_specular;
	}

protected:
	// Memner Variables

	vec3		m_ambient;			// Ambient Color
	vec3		m_diffuse;			// Difuse Color
	vec3		m_specular;			// Specular Color
};

#endif // LIGHT_H
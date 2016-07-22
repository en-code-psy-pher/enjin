#pragma once

#include "config.h"

class Light
{
public:
	vec3 m_ambient;
	vec3 m_diffuse;
	vec3 m_specular;

	// Constructor
	Light();
	Light(vec3 ambient, vec3 diffuse, vec3 specular);
};


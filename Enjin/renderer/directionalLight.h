#pragma once

#include "light.h"

class DirectionalLight : public Light
{
public:
	vec3 m_direction;

	// Constructors
	DirectionalLight();
	DirectionalLight(vec3 direction, vec3 ambient, vec3 diffuse, vec3 specular);
};


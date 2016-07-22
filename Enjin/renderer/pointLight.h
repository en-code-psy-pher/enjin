#pragma once

#include "light.h"

class PointLight : public Light
{
public:
	float m_constant;
	float m_linear;
	float m_quadratic;

	vec3 m_position;

	// Constructors
	PointLight();
	PointLight(vec3 position, float constant, float linear, float quadratic, vec3 ambient, vec3 diffuse, vec3 specular);
};


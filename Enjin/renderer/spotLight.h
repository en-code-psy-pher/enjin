#pragma once

#include "light.h"

class SpotLight : public Light
{
public:
	float m_cutOff;
	float m_outerCutOff;

	float m_constant;
	float m_linear;
	float m_quadratic;

	vec3 m_position;
	vec3 m_direction;

	// Constructors
	SpotLight();
	SpotLight(vec3 position, vec3 direction, float constant, float linear, float quadratic, vec3 ambient, vec3 diffuse, vec3 specular, float cutOff, float outerCutOff);
};


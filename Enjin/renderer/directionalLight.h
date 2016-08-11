#pragma once

#include "light.h"

class DirectionalLight : public Light
{
public:
	// Constructors
	DirectionalLight();
	DirectionalLight(vec3 direction, vec3 ambient, vec3 diffuse, vec3 specular);

	// Destructor
	~DirectionalLight();

	// Inline Functions
	inline void SetDirection(const vec3& direction)
	{
		this->m_direction= direction;
	}

	inline vec3 GetDirection() const
	{
		return this->m_direction;
	}

private:
	vec3 m_direction;
};


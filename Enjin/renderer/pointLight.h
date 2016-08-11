#pragma once

#include "light.h"

class PointLight : public Light
{
public:
	// Constructors
	PointLight();
	PointLight(vec3 position, float constant, float linear, float quadratic, vec3 ambient, vec3 diffuse, vec3 specular);

	// Destructor
	~PointLight();

	// Inline Functions
	inline void SetPosition(const vec3& position)
	{
		this->m_position = position;
	}

	inline void SetConstant(const float& constant)
	{
		this->m_constant = constant;
	}

	inline void SetLinear(const float& linear)
	{
		this->m_linear = linear;
	}

	inline void SetQuadratic(const float& quadratic)
	{
		this->m_quadratic = quadratic;
	}

	inline vec3 GetPosition() const
	{
		return this->m_position;
	}

	inline float GetConstant() const
	{
		return this->m_constant;
	}

	inline float GetLinear() const
	{
		return this->m_linear;
	}

	inline float GetQuadratic() const
	{
		return this->m_quadratic;
	}

private:
	float	m_constant;
	float	m_linear;
	float	m_quadratic;

	vec3	m_position;
};


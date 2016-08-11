#pragma once

#include "light.h"

class SpotLight : public Light
{
public:
	// Constructors
	SpotLight();
	SpotLight(vec3 position, vec3 direction, float constant, float linear, float quadratic, vec3 ambient, vec3 diffuse, vec3 specular, float cutOff, float outerCutOff);

	// Destructor
	~SpotLight();

	// Inline Functions
	inline void SetPosition(const vec3& position)
	{
		this->m_position = position;
	}

	inline void SetDirection(const vec3& direction)
	{
		this->m_direction = direction;
	}

	inline void SetCutoff(const float& cutoff)
	{
		this->m_cutOff = cutoff;
	}

	inline void SetOuterCutoff(const float& outerCutoff)
	{
		this->m_outerCutOff = outerCutoff;
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

	inline vec3 GetDirection() const
	{
		return this->m_direction;
	}

	inline float GetCutoff() const
	{
		return this->m_cutOff;
	}

	inline float GetOuterCutoff() const
	{
		return this->m_outerCutOff;
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
	float	m_cutOff;
	float	m_outerCutOff;

	float	m_constant;
	float	m_linear;
	float	m_quadratic;

	vec3	m_position;
	vec3	m_direction;
};


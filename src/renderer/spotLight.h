#ifndef SPOT_LIGHT_H
#define SPOT_LIGHT_H

#include "light.h"

class SpotLight : public Light
{
public:
	// Constructors

	SpotLight();												// Default Constructor
	SpotLight(vec3 position, vec3 direction,					// Parameter Constructor
			  float constant, float linear, float quadratic, 
			  vec3 ambient, vec3 diffuse, vec3 specular, 
			  float cutOff, float outerCutOff);
	SpotLight(const SpotLight& other);							// Copy Constructor (lvalue)
	SpotLight(const SpotLight&& other);							// Move Constructor (rvalue)

	SpotLight& operator=(const SpotLight& other);				// Copy Assignment (lvalue)
	SpotLight& operator=(const SpotLight&& other);				// Move Assignment (rvalue)

	// Getters & Setters

	// Set Light Position
	inline void SetPosition(const vec3& position)
	{
		this->m_position = position;
	}

	// Set Light Direction
	inline void SetDirection(const vec3& direction)
	{
		this->m_direction = direction;
	}

	// Set Spot Light Cut Off Angle
	inline void SetCutoff(const float& cutoff)
	{
		this->m_cutOff = cutoff;
	}

	// Set Spot Light Outer Cut Off Angle
	inline void SetOuterCutoff(const float& outerCutoff)
	{
		this->m_outerCutOff = outerCutoff;
	}

	// Set Attenuation Constant
	inline void SetConstant(const float& constant)
	{
		this->m_constant = constant;
	}

	// Set Attenuation Linear Constant
	inline void SetLinear(const float& linear)
	{
		this->m_linear = linear;
	}

	// Set Attenuation Quadratic Constant
	inline void SetQuadratic(const float& quadratic)
	{
		this->m_quadratic = quadratic;
	}

	// Get Light Position
	inline vec3 GetPosition() const
	{
		return this->m_position;
	}

	// Get Light Direction
	inline vec3 GetDirection() const
	{
		return this->m_direction;
	}

	// Get Spot Light Cut Off Angle
	inline float GetCutoff() const
	{
		return this->m_cutOff;
	}

	// Get Spot Light Outer Cut Off Angle
	inline float GetOuterCutoff() const
	{
		return this->m_outerCutOff;
	}

	// Get Attenuation Constant
	inline float GetConstant() const
	{
		return this->m_constant;
	}

	// Get Attenuation Linear Constant
	inline float GetLinear() const
	{
		return this->m_linear;
	}

	// Get Attenuation Quadratic Constant
	inline float GetQuadratic() const
	{
		return this->m_quadratic;
	}

private:
	// Member Variables

	float		m_cutOff;			// Cut off angle
	float		m_outerCutOff;		// Outer cut off angle
	float		m_constant;			// Attentuation, Constant factor
	float		m_linear;			// Attentuation, Linear factor
	float		m_quadratic;		// Attentuation, Quadratic factor

	vec3		m_position;			// Light Position
	vec3		m_direction;		// Light Direction
};

#endif // SPOT_LIGHT_H
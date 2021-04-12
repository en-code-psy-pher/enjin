#ifndef POINT_LIGHT_H
#define POINT_LIGHT_H

#include "light.h"

class PointLight : public Light
{
public:
	// Constructors

	PointLight();																// Default Constructor
	PointLight(vec3 position, float constant, float linear, 
			   float quadratic, vec3 ambient, vec3 diffuse, vec3 specular);		// Parameter Constructor
	PointLight(const PointLight& other);										// Copy Constructor (lvalue)
	PointLight(const PointLight&& other);										// Move Constructor (rvalue)

	PointLight& operator=(const PointLight& other);								// Copy Assignment (lvalue)
	PointLight& operator=(const PointLight&& other);							// Move Assignment (rvalue)

	// Getters & Setters

	// Set Light Position
	inline void SetPosition(const vec3& position)
	{
		this->m_position = position;
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

	float		m_constant;			// Attentuation, Constant factor
	float		m_linear;			// Attentuation, Linear factor
	float		m_quadratic;		// Attentuation, Quadratic factor

	vec3		m_position;			// Light Position
};

#endif // POINT_LIGHT_H
#ifndef DIRECTIONAL_LIGHT_H
#define DIRECTIONAL_LIGHT_H

#include "light.h"

class DirectionalLight : public Light
{
public:
	// Constructors

	DirectionalLight();												// Default Constructor
	DirectionalLight(vec3 direction, vec3 ambient,					// Parameter Constructor
					 vec3 diffuse, vec3 specular);
	DirectionalLight(const DirectionalLight& other);				// Copy Constructor (lvalue)
	DirectionalLight(const DirectionalLight&& other);				// Move Constructor (rvalue)

	DirectionalLight& operator=(const DirectionalLight& other);		// Copy Assignment (lvalue)
	DirectionalLight& operator=(const DirectionalLight&& other);	// Move Assignment (rvalue)

	// Getters & Setters

	// Set Light Direction
	inline void SetDirection(const vec3& direction)
	{
		this->m_direction= direction;
	}

	// Get Light Direction
	inline vec3 GetDirection() const
	{
		return this->m_direction;
	}

private:
	// Member Variables

	vec3		m_direction;		// Light Direction
};

#endif // DIRECTIONAL_LIGHT_H
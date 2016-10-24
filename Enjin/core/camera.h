#ifndef CAMERA_H
#define CAMERA_H

#include "../core/config.h"

class Camera
{
public:
	// Constructors
	Camera();
	Camera(const Camera& other);					// Copy Constructor (lvalue)
	Camera(const Camera&& other);					// Move Constructor (lvalue)

	Camera& operator=(const Camera& other);			// Copy Assignment (lvalue)
	Camera& operator=(const Camera&& other);		// Move Assignment (rvalue)

	// Methods
	void Update();									// Update Camera

	/*
	TODO:
	- Camera class should use quaternions
	*/


	// Getters & Setters
	// Get Camera Position
	inline vec3 GetPositon() const
	{
		return this->m_position;
	}

	// Get View Matrix
	inline mat4 GetViewMatrix() const
	{
		return this->m_viewMatrix;
	}

	// Get Projection Matrix
	inline mat4 GetProjectionMatrix() const
	{
		return this->m_projectionMatrix;
	}


	// Member Variables
	GLfloat		m_width;
	GLfloat		m_height;

	vec3		m_position;						// Camera Position
	vec3		m_direction;					// Camera Direction
	vec3		m_fowardDirection;				// Camera Foward Direction
	vec3		m_right;						// Camera Right Vector
	vec3		m_up;							// Camera Up Vector

	mat4		m_viewMatrix;					// View Matrix
	mat4		m_projectionMatrix;				// Projection or Perspective Matrix
};

#endif // CAMERA_H
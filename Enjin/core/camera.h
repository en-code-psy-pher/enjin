#ifndef CAMERA_H
#define CAMERA_H

#include "../core/config.h"

class Camera
{
public:
	// Constructors
	Camera();
	Camera(const GLfloat& width, const GLfloat& height);
	Camera(const Camera& other);																	// Copy Constructor (lvalue)
	Camera(const Camera&& other);																	// Move Constructor (lvalue)

	Camera& operator=(const Camera& other);															// Copy Assignment (lvalue)
	Camera& operator=(const Camera&& other);														// Move Assignment (rvalue)

	// Methods
	void ProcessMouseMovement(GLfloat xOffset, GLfloat yOffset, GLboolean constrainPitch = true);
	void Update();																					// Update Camera

	/*
	TODO:
	- Camera class should use quaternions
	*/


	// Getters & Setters

	// Get Camera Position
	inline vec3 GetPosition() const
	{
		return this->m_position;
	}

	// Get Camera Direction
	inline vec3 GetDirection() const
	{
		return this->m_fowardDirection;
	}

	// Get Camera Right Vector
	inline vec3 GetRight() const
	{
		return glm::normalize(glm::cross(m_fowardDirection, m_up));
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

	GLfloat		m_yaw;
	GLfloat		m_pitch;

	vec3		m_position;						// Camera Position
	vec3		m_fowardDirection;				// Camera Foward Direction
	vec3		m_right;						// Camera Right Vector
	vec3		m_up;							// Camera Up Vector

	mat4		m_viewMatrix;					// View Matrix
	mat4		m_projectionMatrix;				// Projection or Perspective Matrix
};

#endif // CAMERA_H
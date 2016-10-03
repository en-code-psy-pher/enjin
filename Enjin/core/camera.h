/* 
	TODO: 
	- Camera class should use quaternions
*/

#ifndef CAMERA_H
#define CAMERA_H

#include "config.h"

#define CAMERA_SPEED 10.0f

class Camera
{
public:
	// Constructors

	Camera();										// Constructor
	Camera(vec3 position, vec3 up, vec3 heading);	// Parameter Constructor
	Camera(const Camera& other);					// Copy Constructor (lvalue)
	Camera(const Camera&& other);					// Move Constructor (lvalue)

	Camera& operator=(const Camera& other);			// Copy Assignment (lvalue)
	Camera& operator=(const Camera&& other);		// Move Assignment (rvalue)

	// Methods
	
	void Update();									// Update Camera

	// Getters & Setters
	
	// Set Camera Position
	inline void SetPosition(const vec3& pos)		
	{
		this->m_position = pos;
	}

	// Set Camera Heading
	inline void SetHeading(const vec3& heading)
	{
		this->m_heading = heading;
	}

	// Get Camera Position
	inline vec3 GetPositon() const
	{
		return this->m_position;
	}

	// Get Camera Heading
	inline vec3 GetHeading() const
	{
		return this->m_heading;
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

private:
	// Member Variables

	vec3		m_position;					// Camera Position
	vec3		m_heading;					// Camera Heading
	vec3		m_up;						// Camera Up Vector

	mat4		m_viewMatrix;				// View Matrix
	mat4		m_projectionMatrix;			// Projection or Perspective Matrix
};

#endif // CAMERA_H
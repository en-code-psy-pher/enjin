#pragma once

#include "config.h"

#define CAMERA_SPEED 10.0f

class Camera
{
public:
	// Constructor
	Camera();

	// Destructor
	~Camera();

	// Functions
	void Reset();
	void Move(vec3 direction);
	void Update();

	// Inline Functions
	inline void SetPosition(const vec3& pos)
	{
		this->m_position = pos;
	}

	inline void SetHeading(const vec3& heading)
	{
		this->m_heading = heading;
	}

	inline vec3 GetPositon() const
	{
		return this->m_position;
	}

	inline vec3 GetHeading() const
	{
		return this->m_heading;
	}

	inline mat4 GetViewMatrix() const
	{
		return this->m_viewMatrix;
	}

	inline mat4 GetProjectionMatrix() const
	{
		return this->m_projectionMatrix;
	}

private:
	vec3 m_position;
	vec3 m_heading;

	mat4 m_viewMatrix;
	mat4 m_projectionMatrix;
};
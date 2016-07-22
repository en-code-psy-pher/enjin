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
	// Reset the camera to default
	void Reset();
	
	// Move the camera along a direction
	void Move(vec3 direction);
	
	// Updates the camera
	void Update();

	// Change the pitch (up, down) for the free camera
	void ChangePitch(float degrees);
	
	// Change heading (left, right) for the free camera
	void ChangeHeading(float degrees);

	// Inline Functions
	inline void SetPosition(const vec3& pos)
	{
		this->position = pos;
	}

	inline void SetDirection(const vec3& dir)
	{
		this->direction = dir;
	}

	inline vec3 GetPositon() const
	{
		return this->position;
	}

	inline vec3 GetDirection() const
	{
		return this->direction;
	}

	inline mat4 GetViewMatrix() const
	{
		return this->viewMatrix;
	}

	inline mat4 GetProjectionMatrix() const
	{
		return this->projectionMatrix;
	}

private:
	vec3 position;
	vec3 direction;

	mat4 viewMatrix;
	mat4 projectionMatrix;
	
	// Functions
};
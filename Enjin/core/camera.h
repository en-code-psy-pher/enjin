#pragma once

#include "config.h"

// Default camera values
const GLfloat YAW = -90.0f;
const GLfloat PITCH = 0.0f;
const GLfloat SPEED = 3.0f;
const GLfloat SENSITIVTY = 0.25f;
const GLfloat ZOOM = 45.0f;

enum CameraMovement {
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT
};

class Camera
{
public:
	// Camera attributes
	vec3 m_position;
	vec3 m_up;
	vec3 m_worldUp;
	vec3 m_right;
	vec3 m_frontHeading;

	// Camera options
	GLfloat m_movementSpeed;
	GLfloat m_mouseSensitivity;
	GLfloat m_zoom;
	
	// Euler Angles
	GLfloat m_yaw;
	GLfloat m_pitch;

	// Constructor
	Camera();

	// Functions
	mat4 GetViewMatrix();
	void ProcessKeyboard(CameraMovement direction, GLfloat deltaTime);
	void ProcessMouseMovement(GLfloat xOffset, GLfloat yOffset, GLboolean constrainPitch = true);
	void ProcessMouseScroll(GLfloat yOffset);

private:
	// Functions
	void UpdateCameraVectors();
};


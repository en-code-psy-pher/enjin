#include "camera.h"

Camera::Camera() {}

Camera::Camera(const GLfloat& width, const GLfloat& height)
{
	m_position = vec3(0.0f, 0.0f, 3.0f);
	m_up = vec3(0.0f, 1.0f, 0.0f);
	m_fowardDirection = vec3(0.0f, 0.0f, -1.0f);
	m_right = glm::normalize(glm::cross(m_fowardDirection, m_up));

	m_yaw = -90.0f;
	m_pitch = 0.0f;

	m_viewMatrix = glm::lookAt(this->m_position, this->m_position + m_fowardDirection, this->m_up);
	m_projectionMatrix = glm::perspective(45.0f, width / height, 0.1f, 1000.0f);
}

// TODO - COMPLETE CONSTRUCTORS

// Copy Constructor (lvalue)
Camera::Camera(const Camera & other)
{
	this->m_position = other.m_position;
	this->m_fowardDirection = other.m_fowardDirection;
	this->m_right = other.m_right;
	this->m_up = other.m_up;

	this->m_projectionMatrix = other.m_projectionMatrix;
	this->m_viewMatrix = other.m_viewMatrix;
}

// Move Constructor (rvalue)
Camera::Camera(const Camera && other)
{
	this->m_position = other.m_position;
	this->m_fowardDirection = other.m_fowardDirection;
	this->m_right = other.m_right;
	this->m_up = other.m_up;

	this->m_projectionMatrix = other.m_projectionMatrix;
	this->m_viewMatrix = other.m_viewMatrix;
}

// Copy Assignment (lvalue)
Camera & Camera::operator=(const Camera & other)
{
	// Self assignment guard
	if (this == &other)
		return *this;

	this->m_position = other.m_position;
	this->m_fowardDirection = other.m_fowardDirection;
	this->m_right = other.m_right;
	this->m_up = other.m_up;

	this->m_projectionMatrix = other.m_projectionMatrix;
	this->m_viewMatrix = other.m_viewMatrix;

	return *this;
}

// Move Assignment (rvalue)
Camera & Camera::operator=(const Camera && other)
{
	assert(this != &other);

	this->m_position = other.m_position;
	this->m_fowardDirection = other.m_fowardDirection;
	this->m_right = other.m_right;
	this->m_up = other.m_up;
	
	this->m_projectionMatrix = other.m_projectionMatrix;
	this->m_viewMatrix = other.m_viewMatrix;

	return *this;
}

void Camera::ProcessMouseMovement(GLfloat xOffset, GLfloat yOffset, GLboolean constrainPitch)
{
	xOffset *= 0.25f;
	yOffset *= 0.25f;

	this->m_yaw += xOffset;
	this->m_pitch += yOffset;

	// Make sure that when pitch is out of bounds, screen doesn't get flipped
	if (constrainPitch)
	{
		if (this->m_pitch > 89.0f)
			this->m_pitch = 89.0f;
		if (this->m_pitch < -89.0f)
			this->m_pitch = -89.0f;
	}

	// Update Front, Right and Up Vectors using the updated Eular angles
	this->Update();
}

// Update Camera every tick
void Camera::Update()
{
	// Calculate the new Front vector
	glm::vec3 front;
	front.x = cos(glm::radians(this->m_yaw)) * cos(glm::radians(this->m_pitch));
	front.y = sin(glm::radians(this->m_pitch));
	front.z = sin(glm::radians(this->m_yaw)) * cos(glm::radians(this->m_pitch));
	this->m_fowardDirection = glm::normalize(front);

	m_viewMatrix = glm::lookAt(this->m_position, this->m_position + m_fowardDirection, this->m_up);
}
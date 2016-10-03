#include "camera.h"

// Default Constructor
Camera::Camera()
	: m_position(vec3(0.0f, -2.5f, -5.0f)), m_up(vec3(0.0f, 1.0f, 0.0f)), m_heading(vec3(1.0f, 0.0f, 1.0f)), 
	  m_projectionMatrix(mat4(1.0f)), m_viewMatrix(mat4(1.0f))
{
}

// Parameter Constructor
Camera::Camera(vec3 position, vec3 up, vec3 heading)
	: m_position(position), m_up(up), m_heading(heading),
	  m_projectionMatrix(mat4(1.0f)), m_viewMatrix(mat4(1.0f))
{
}

// Copy Constructor (lvalue)
Camera::Camera(const Camera & other)
{
	this->m_position = other.m_position;
	this->m_heading = other.m_heading;
	this->m_up = other.m_up;

	this->m_projectionMatrix = other.m_projectionMatrix;
	this->m_viewMatrix = other.m_viewMatrix;
}

// Move Constructor (rvalue)
Camera::Camera(const Camera && other)
{
	this->m_position = other.m_position;
	this->m_heading = other.m_heading;
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
	this->m_heading = other.m_heading;
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
	this->m_heading = other.m_heading;
	this->m_up = other.m_up;

	this->m_projectionMatrix = other.m_projectionMatrix;
	this->m_viewMatrix = other.m_viewMatrix;

	return *this;
}

// Update Camera every tick
void Camera::Update()
{
}
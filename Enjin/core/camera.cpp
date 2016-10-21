#include "camera.h"

// Default Constructor
Camera::Camera()
	: m_position(vec3(0.0f, 0.0f, 5.0f)), m_up(vec3(0.0f, 1.0f, 0.0f)), m_heading(vec3(0.0f, 0.0f, 0.0f))
{
	m_width = 800.0f;
	m_height = 600.0f;

	m_viewMatrix = glm::lookAt(this->m_position, this->m_heading, this->m_up);
	m_projectionMatrix = glm::perspective(45.0f, m_width / m_height, 0.01f, 100.0f);
}

// Parameter Constructor
Camera::Camera(vec3 position, vec3 up, vec3 heading, GLfloat width, GLfloat height)
	: m_position(position), m_up(up), m_heading(heading), m_width(width), m_height(height)
{
	m_viewMatrix = glm::lookAt(this->m_position, this->m_heading, this->m_up);
	m_projectionMatrix = glm::perspective(45.0f, m_width / m_height, 0.01f, 100.0f);
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

void Camera::Move()
{
	vec3 amtMove = this->m_heading  * CAMERA_SPEED;
	this->m_position += amtMove;
}

// Update Camera every tick
void Camera::Update()
{
	m_viewMatrix = glm::lookAt(this->m_position, this->m_heading, this->m_up);
}
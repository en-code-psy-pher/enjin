#include "camera.h"

// Default Constructor
Camera::Camera()
{
	m_width = 800.0f;
	m_height = 600.0f;

	m_position = vec3(0.0f, 0.0f, 3.0f);
	m_up = vec3(0.0f, 1.0f, 0.0f);
	m_fowardDirection = vec3(0.0f, 0.0f, -1.0f);

	m_viewMatrix = glm::lookAt(this->m_position, this->m_position + m_fowardDirection, this->m_up);
	
	cout << "HIT" << endl;

	m_direction = vec3(m_viewMatrix[2][0], m_viewMatrix[2][1], m_viewMatrix[2][2]);
	for (int i = 0; i < m_direction.length(); ++i)
		cout << m_direction[i] << endl;

	m_projectionMatrix = glm::perspective(45.0f, m_width / m_height, 0.1f, 1000.0f);
}

// TODO - COMPLETE CONSTRUCTORS

// Copy Constructor (lvalue)
Camera::Camera(const Camera & other)
{
	this->m_position = other.m_position;
	
	this->m_projectionMatrix = other.m_projectionMatrix;
	this->m_viewMatrix = other.m_viewMatrix;
}

// Move Constructor (rvalue)
Camera::Camera(const Camera && other)
{
	this->m_position = other.m_position;
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
	this->m_up = other.m_up;
	
	this->m_projectionMatrix = other.m_projectionMatrix;
	this->m_viewMatrix = other.m_viewMatrix;

	return *this;
}

// Update Camera every tick
void Camera::Update()
{
	m_viewMatrix = glm::lookAt(this->m_position, this->m_position + m_fowardDirection, this->m_up);
}
#include "camera.h"

Camera::Camera()
	: m_position(vec3(0.0f, -2.5f, -5.0f)), m_heading(vec3(1.0f, 0.0f, 1.0f)), 
	  m_projectionMatrix(mat4(1.0f)), m_viewMatrix(mat4(1.0f))
{
}

Camera::~Camera()
{
}

void Camera::Reset()
{
}

void Camera::Move(vec3 direction)
{
}

void Camera::Update()
{
}
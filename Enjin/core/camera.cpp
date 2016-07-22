#include "camera.h"

Camera::Camera()
	: m_position(vec3(0.0f, 1.0f, 5.0f)), m_worldUp(vec3(0.0f, 1.0f, 0.0f)),
	  m_frontHeading(vec3(0.0f, 0.0f, -1.0f)), 
	  m_movementSpeed(SPEED), m_mouseSensitivity(SENSITIVTY),
	  m_zoom(ZOOM), m_yaw(YAW), m_pitch(PITCH)
{
	this->UpdateCameraVectors();
}

mat4 Camera::GetViewMatrix()
{
	return glm::lookAt(this->m_position, this->m_position + this->m_frontHeading, this->m_up);
}

void Camera::ProcessKeyboard(CameraMovement direction, GLfloat deltaTime)
{
	GLfloat velocity = this->m_movementSpeed * deltaTime;
	if (direction == FORWARD)
		this->m_position += this->m_frontHeading * velocity;
	if (direction == BACKWARD)
		this->m_position -= this->m_frontHeading * velocity;
	if (direction == LEFT)
		this->m_position -= this->m_right * velocity;
	if (direction == RIGHT)
		this->m_position += this->m_right * velocity;
}

void Camera::ProcessMouseMovement(GLfloat xOffset, GLfloat yOffset, GLboolean constrainPitch)
{
	xOffset *= this->m_mouseSensitivity;
	yOffset *= this->m_mouseSensitivity;

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

	this->UpdateCameraVectors();
}

void Camera::ProcessMouseScroll(GLfloat yOffset)
{
	if (this->m_zoom >= 1.0f && this->m_zoom <= 45.0f)
		this->m_zoom -= yOffset;
	if (this->m_zoom <= 1.0f)
		this->m_zoom = 1.0f;
	if (this->m_zoom >= 45.0f)
		this->m_zoom = 45.0f;
}

// Update Front Heading, Right and Up Vectors using the updated Eular angles
void Camera::UpdateCameraVectors()
{
	glm::vec3 front;
	front.x = cos(glm::radians(this->m_yaw)) * cos(glm::radians(this->m_pitch));
	front.y = sin(glm::radians(this->m_pitch));
	front.z = sin(glm::radians(this->m_yaw)) * cos(glm::radians(this->m_pitch));
	this->m_frontHeading = glm::normalize(front);

	this->m_right = glm::normalize(glm::cross(this->m_frontHeading, this->m_worldUp));
	this->m_up = glm::normalize(glm::cross(this->m_right, this->m_frontHeading));
}


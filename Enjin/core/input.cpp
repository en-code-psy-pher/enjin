#include "input.h"

Input::Input(GLint width, GLint height, Camera& camera)
	: m_windowWidth(width), m_windowHeight(height),
	  m_mainCamera(camera)
{
	m_firstMouse = true;

	m_lastX = GLfloat(m_windowWidth) / 2.0f;
	m_lastY = GLfloat(m_windowHeight) / 2.0f;
}

void Input::HandleKeyboardCallblack(GLFWwindow * window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);

	if (key >= 0 && key < 1024)
	{
		if (action == GLFW_PRESS)
			m_keys[key] = true;
		else if (action == GLFW_RELEASE)
			m_keys[key] = false;
	}
}

void Input::HandleMouseCallblack(double xpos, double ypos)
{
	if (m_firstMouse)
	{
		m_lastX = (GLfloat)xpos;
		m_lastY = (GLfloat)ypos;

		m_firstMouse = false;
	}

	GLfloat xoffset = (GLfloat)xpos - m_lastX;
	GLfloat yoffset = m_lastY - (GLfloat)ypos;  // Reversed since y-coordinates go from bottom to left

	m_lastX = (GLfloat)xpos;
	m_lastY = (GLfloat)ypos;

	m_mainCamera.ProcessMouseMovement(xoffset, yoffset);
}

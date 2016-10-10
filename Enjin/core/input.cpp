#include "input.h"

// Default Constructor
Input::Input()
{
}

// Parameter Constructor
Input::Input(const GLfloat width, GLfloat height)
{
	m_firstMouse = true;

	m_lastX = width * 0.5f;
	m_lastY = height * 0.5f;
}

// Handle keyboard callbacks
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

// Handle mouse callbacks
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
}

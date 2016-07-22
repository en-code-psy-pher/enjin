#pragma once

#include "config.h"

#include "camera.h"

class Input
{
public:
	// Constructor
	Input(GLint width, GLint height, Camera& camera);

	// Functions
	void HandleKeyboardCallblack(GLFWwindow * window, int key, int scancode, int action, int mode);
	void HandleMouseCallblack(double xpos, double ypos);

	bool			m_keys[1024];

private:
	bool			m_firstMouse;

	GLfloat			m_lastX;
	GLfloat			m_lastY;
	
	GLint			m_windowWidth;
	GLint			m_windowHeight;

	Camera			m_mainCamera;
};



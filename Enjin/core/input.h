#ifndef INPUT_H
#define INPUT_H

#include "config.h"

class Input
{
public:
	// Constructors

	Input();															// Default Constructor

	// Methods

	void HandleKeyboardCallblack(GLFWwindow * window, int key,			// Handle keyboard callbacks
								 int scancode, int action, int mode);	// Handle mouse callbacks
	void HandleMouseCallblack(double xpos, double ypos);

	// Member Variables

	bool			m_keys[1024];

private:
	// Member Variables

	bool			m_firstMouse;

	GLfloat			m_lastX;
	GLfloat			m_lastY;
};

#endif	// INPUT_H
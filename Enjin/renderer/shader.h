#pragma once

#include "config.h"

class Shader
{
public:
	// Constructor
	Shader();
	Shader(const GLchar* vertexPath, const GLchar* fragmentPath);

	~Shader();

	// Functions
	void Use();

	GLuint m_program;
};


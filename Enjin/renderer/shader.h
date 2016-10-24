/*
	TODO:
	- Store the uniform names
	- Store the uniform and attributes in a hash table, where the name is the key
	-> The value stored will be a pointer to the address of the uniforms value (values can change during the flow of the program, such as the view matrix)
*/

#ifndef SHADER_H
#define SHADER_H

#include "config.h"

class Shader
{
public:
	// Constructors

	Shader();														// Default Constructor
	Shader(const GLchar* vertexPath, const GLchar* fragmentPath);	// Parameter Constructor
	Shader(const GLchar* vertexPath, const GLchar* fragmentPath, const GLchar* geometryPath);	// Parameter Constructor

	// Methods
	
	void Use();														// Use Shader Program

	// Getters & Setters
	
	// Get Shader Program
	inline GLuint GetProgram() const
	{
		return this->m_program;
	}

private:
	// Member Variables

	GLuint m_program;
};

#endif // SHADER_H
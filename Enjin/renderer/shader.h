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

	// Methods

	void SetUniform(const string& name, const GLuint& value);		// Set Uniforms, int val
	void SetUniform(const string& name, const GLfloat& value);		// Set Uniforms, float val
	void SetUniform(const string& name, const vec3& vector);		// Set Uniforms, vec3 val
	void SetUniform(const string& name, const mat4& value);			// Set Uniforms, mat4 val
	
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
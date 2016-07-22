#pragma once

#include "config.h"

class Shader
{
public:
	// Constructor
	Shader(const GLchar* vertexPath, const GLchar* fragmentPath);

	inline void SetUniform(int location, const GLuint& value);
	inline void SetUniform(int location, const GLfloat& value);
	inline void SetUniform(int location, const vec3& vector);
	inline void SetUniform(int location, const mat4& value);
	
	template<typename T>
	inline void SetUniform(const string& name, T&& value);

	~Shader();

	// Functions
	void Use();

private:
	GLuint m_program;
};

void Shader::SetUniform(int location, const GLuint& value)
{
	glUniform1i(location, value);
}

void Shader::SetUniform(int location, const GLfloat& value)
{
	glUniform1f(location, value);
}

void Shader::SetUniform(int location, const vec3& vector)
{
	glUniform3f(location, vector.x, vector.y, vector.z);
}

void Shader::SetUniform(int location, const mat4& value)
{
	glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(value));
}

template <typename T>
void Shader::SetUniform(const string& name, T&& value)
{
	int location = glGetUniformLocation(this->m_program, name.c_str());

	if (location == -1)
	{
		string error = "Program could not find location of uniform " + name;
		throw std::runtime_error(error);
	}

	SetUniform(location, std::forward<T>(value));
}
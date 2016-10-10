#include "shader.h"

Shader::Shader() :
	m_program(NULL)
{
}

Shader::Shader(const GLchar* vertexPath, const GLchar* fragmentPath)
{
	string vertexCode;
	string fragmentCode;
	std::ifstream vShaderFile;
	std::ifstream fShaderFile;

	// Read the GLSL files
	// ifstream objects can throw exceptions
	vShaderFile.exceptions(std::ifstream::badbit);
	fShaderFile.exceptions(std::ifstream::badbit);

	try
	{
		vShaderFile.open(vertexPath);
		fShaderFile.open(fragmentPath);
		std::stringstream vShaderStream, fShaderStream;
		// Read file's buffer contents into streams
		vShaderStream << vShaderFile.rdbuf();
		fShaderStream << fShaderFile.rdbuf();
		vShaderFile.close();
		fShaderFile.close();
		// Convert stream into GLchar array
		vertexCode = vShaderStream.str();
		fragmentCode = fShaderStream.str();
	}
	catch (std::ifstream::failure e)
	{
		cout << "Shader file not sucessfully read" << endl;
	}

	const GLchar* vShaderCode = vertexCode.c_str();
	const GLchar* fShaderCode = fragmentCode.c_str();

	// Compile shaders
	GLuint vertex, fragment;
	GLint success;
	GLchar infoLog[512];

	// Vertex Shader
	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vShaderCode, NULL);
	glCompileShader(vertex);
	glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertex, 512, NULL, infoLog);
		cout << "Vertex Compilation Failed!!" << infoLog << endl;
	}

	// Fragment Shader
	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fShaderCode, NULL);
	glCompileShader(fragment);
	glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragment, 512, NULL, infoLog);
		cout << "Fragment Compilation Failed!!" << infoLog << endl;
	}

	// Create shader program
	this->m_program = glCreateProgram();
	glAttachShader(this->m_program, vertex);
	glAttachShader(this->m_program, fragment);
	glLinkProgram(this->m_program);
	glGetShaderiv(this->m_program, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragment, 512, NULL, infoLog);
		cout << "Program Linking Failed!!" << infoLog << endl;
	}

	// Delete shaders
	glDeleteShader(vertex);
	glDeleteShader(fragment);
}

void Shader::SetUniform(const string& name, const GLuint& value)
{
	int location = glGetUniformLocation(this->m_program, name.c_str());

	if (location == -1)
	{
		string error = "Program could not find location of uniform " + name;
		throw std::runtime_error(error);
	}

	glUniform1i(location, value);
}

void Shader::SetUniform(const string& name, const GLfloat& value)
{
	int location = glGetUniformLocation(this->m_program, name.c_str());

	if (location == -1)
	{
		string error = "Program could not find location of uniform " + name;
		throw std::runtime_error(error);
	}

	glUniform1f(location, value);
}

void Shader::SetUniform(const string& name, const vec3& vector)
{
	int location = glGetUniformLocation(this->m_program, name.c_str());

	if (location == -1)
	{
		string error = "Program could not find location of uniform " + name;
		throw std::runtime_error(error);
	}

	glUniform3f(location, vector.x, vector.y, vector.z);
}

void Shader::SetUniform(const string& name, const mat4& value)
{
	int location = glGetUniformLocation(this->m_program, name.c_str());

	if (location == -1)
	{
		string error = "Program could not find location of uniform " + name;
//		throw std::runtime_error(error);
	}

	glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(value));
}

void Shader::Use()
{
	glUseProgram(this->m_program);
}
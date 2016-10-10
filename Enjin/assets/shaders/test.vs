#version 330 core

layout (location = 0) in vec3 _position;
layout (location = 1) in vec3 _nomral;
layout (location = 2) in vec2 _texCoord;

uniform mat4 _mvpMat;
uniform mat4 _modelMat;
uniform mat4 _normalMat;

out vec2 texCoord;
out vec3 fragPos;
out vec3 normal;

void main()
{
	gl_Position = _mvpMat * vec4(_position, 1.0);
	
	fragPos = vec3(_modelMat * vec4(_position, 1.0));
	
	normal = vec3(_normalMat * vec4(_nomral, 1.0));
	
	// Flip y coordinates for OpenGl
	texCoord = vec2(_texCoord.x, 1.0 - _texCoord.y);
}
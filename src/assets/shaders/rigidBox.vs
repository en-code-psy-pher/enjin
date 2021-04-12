#version 330 core

layout (location = 0) in vec3 _position;
layout (location = 2) in vec3 _normal;
layout (location = 2) in vec2 _texCoord;

uniform mat4 _mvpMat;

out vec2 _TexCoord;

void main()
{
    gl_Position = _mvpMat * vec4(_position, 1.0f);
    
    // We swap the y-axis by substracing our coordinates from 1. 
    // This is done because most images have the top y-axis inversed with OpenGL's top y-axis.
	_TexCoord = vec2(_texCoord.x, 1.0 - _texCoord.y);
}
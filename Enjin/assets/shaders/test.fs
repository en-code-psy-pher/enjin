#version 330 core

in vec2 _texCoord;
in vec3 _normal;
in vec3 _fragPos;

out vec4 color;

void main()
{
	color = vec4(1.0, 0.5, 0.2, 1.0);
}
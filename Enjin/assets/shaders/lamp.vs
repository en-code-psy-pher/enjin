#version 330 core

layout (location = 0) in vec3 _position;

uniform mat4 _mvpMat;

void main()
{
    gl_Position = _mvpMat * vec4(_position, 1.0f);
}
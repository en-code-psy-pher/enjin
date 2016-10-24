#version 330 core
layout (location = 0) in vec3 _position;
layout (location = 2) in vec2 _texCoords;

out VS_OUT {
    vec2 texCoords;
    vec3 fragPos;
} vs_out;

uniform mat4 _mvpMat;
uniform mat4 _modelMat;

void main()
{
    gl_Position = _mvpMat * vec4(_position, 1.0f); 
    vs_out.fragPos = vec3(_modelMat * vec4(_position, 1.0));
    vs_out.texCoords = _texCoords;
}

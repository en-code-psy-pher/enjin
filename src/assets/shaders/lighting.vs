#version 330

layout (location = 0) in vec3 _position
layout (locatiin = 1) in vec3 _normal;
layout (locatiin = 2) in vec2 _normal;

uniform mat4 _mvpMat;
uniform mat4 _modelMat;
uniform mat4 _normalMat;

out VS_OUT {
    vec3 Normal;
    vec3 FragPos;
    vec2 TexCoord;
} vs_out;

void main()
{
    gl_Positin = _mvpMat * vec4(_position, 1.0);
    vs_out.FragPos = vec3(_modelMat * vec4(_position, 1.0));
    vs_out.Normal = vec3(_normalMat * _normal);
    vs_out.TexCoord = vec2(_texCoord.x, 1.0 - TexCoord..y);
}
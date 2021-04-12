#version 330 core

in vec2 _TexCoord;

out vec4 _color;

uniform sampler2D _texture;

void main()
{
    _color = texture(_texture, _TexCoord);
}
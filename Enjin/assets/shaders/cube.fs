#version 330 core
in vec3 ourColor;
in vec2 TexCoord;

out vec4 color;

// Texture samplers
uniform sampler2D testTexture;

void main()
{
	color = texture(testTexture, TexCoord);
}
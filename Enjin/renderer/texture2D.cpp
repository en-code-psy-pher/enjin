#include "texture2D.h"

Texture2D::Texture2D()
{
}

Texture2D::Texture2D(const char * fileName)
{
	uchar* image;
	int width, height;

	image = SOIL_load_image(fileName, &width, &height, 0, SOIL_LOAD_RGB);

	glGenTextures(1, &m_tex);

	glBindTexture(GL_TEXTURE_2D, m_tex);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);

	// Set texture parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// Set texture mipmapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glBindTexture(GL_TEXTURE_2D, 0);

	SOIL_free_image_data(image);
}
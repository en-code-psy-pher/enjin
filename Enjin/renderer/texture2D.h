#ifndef TEXTURE2D_H
#define TEXTURE2D_H

#include "config.h"

// SOIL Lib
#include "SOIL.h"

class Texture2D
{
public:
	// Constructors

	Texture2D();									// Default Constructor

	// Methods

	void CreateTextureUnit(const char* fileName);
	
	// Getters & Setters

	// Get texture
	inline GLuint GetTextureUnit() const
	{
		return this->m_tex;
	}

private:
	// Member Variables

	GLuint		m_tex;
};

#endif // TEXTURE2D_H
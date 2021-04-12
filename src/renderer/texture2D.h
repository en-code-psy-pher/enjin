#ifndef TEXTURE2D_H
#define TEXTURE2D_H

#include "../core/config.h"

// SOIL Lib
#include "../includes/SOIL/SOIL.h"

class Texture2D
{
public:
	// Constructors

	Texture2D();									// Default Constructor
	Texture2D(const char* fileName);				// Parameter Constructor
	
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

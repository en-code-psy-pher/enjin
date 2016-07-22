#pragma once

#include "config.h"

// SOIL Lib
#include "SOIL.h"

class Texture2D
{
public:
	// Constructor
	Texture2D();

	// Destructor
	~Texture2D();

	// Functions
	void CreateTextureUnit(const char* fileName);
	GLuint GetTextureUnit();

	GLuint m_tex;
};


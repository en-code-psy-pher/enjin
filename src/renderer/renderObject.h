#ifndef RENDEROBJECT_H
#define RENDEROBJECT_H

#include "../core/config.h"

class RenderObject
{
public:
	RenderObject();
	RenderObject(GLfloat * attribs, int nAttribs, int nVertices);
	~RenderObject();

	void DrawObject();
	void DrawPoints();

private:
	int					m_nVertices;

	GLuint				m_VAO;
	GLuint				m_VBO;
	GLuint				m_EBO;

	vector<GLuint>		m_indices;
	vector<GLfloat>		m_attribs;

	void CreateMesh();
};

#endif RENDEROBJECT_H

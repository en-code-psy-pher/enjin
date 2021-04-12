#include "renderObject.h"

RenderObject::RenderObject()
{
}

RenderObject::RenderObject(GLfloat * attribs, int nAttribs, int nVertices)
{
	m_attribs = vector<GLfloat>();

	m_nVertices = nVertices;

	for (size_t i = 0; i < nAttribs; ++i)
		m_attribs.push_back(attribs[i]);

	m_indices = vector<GLuint>();

	CreateMesh();
}

RenderObject::~RenderObject()
{
}

void RenderObject::CreateMesh()
{
	// Create buffers/arrays
	glGenVertexArrays(1, &m_VAO);
	glGenBuffers(1, &m_VBO);

	glBindVertexArray(m_VAO);

	// Load data into vertex buffers
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBufferData(GL_ARRAY_BUFFER, m_attribs.size() * sizeof(GLfloat), &m_attribs[0], GL_STATIC_DRAW);

	if (m_indices.size() != 0)
	{
		glGenBuffers(1, &m_EBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indices.size() * sizeof(GLuint), &m_indices[0], GL_STATIC_DRAW);
	}

	// Set the vertex attribute pointers
	// Vertex Positions
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(0 * sizeof(GLfloat)));
	// Vertex Normals
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	// Vertex Texture Coords
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));

	glBindVertexArray(0);
}

void RenderObject::DrawObject()
{
	if (m_indices.size() != 0)
	{
		glBindVertexArray(m_VAO);
		glDrawElements(GL_TRIANGLES, m_indices.size(), GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
	}
	else
	{
		glBindVertexArray(m_VAO);
		glDrawArrays(GL_TRIANGLES, 0, m_nVertices);
		glBindVertexArray(0);
	}
}

void RenderObject::DrawPoints()
{
	glBindVertexArray(m_VAO);
	glDrawArrays(GL_POINTS, 0, m_nVertices);
	glBindVertexArray(0);
}
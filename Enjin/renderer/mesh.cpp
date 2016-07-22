#include "mesh.h"

Mesh::Mesh(vector<Vertex> vertices, vector<GLuint> indices, vector<Texture> textures)
{
	this->m_vertices = vertices;
	this->m_indices = indices;
	this->m_textures = textures;

	// Now that we have all the required data, set the vertex buffers and its attribute pointers.
	this->SetupMesh();
}

// Destroy mesh data
Mesh::~Mesh()
{
}

// Initializes all the buffer objects/arrays
void Mesh::SetupMesh()
{
	// Create buffers/arrays
	glGenVertexArrays(1, &this->m_VAO);
	glGenBuffers(1, &this->m_VBO);
	glGenBuffers(1, &this->m_EBO);

	glBindVertexArray(this->m_VAO);

		// Load data into vertex buffers
		glBindBuffer(GL_ARRAY_BUFFER, this->m_VBO);
		glBufferData(GL_ARRAY_BUFFER, this->m_vertices.size() * sizeof(Vertex), &this->m_vertices[0], GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->m_EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->m_indices.size() * sizeof(GLuint), &this->m_indices[0], GL_STATIC_DRAW);

		// Set the vertex attribute pointers
		// Vertex Positions
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);
		// Vertex Normals
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, normal));
		// Vertex Texture Coords
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, texCoords));

	glBindVertexArray(0);
}

// Render the mesh
void Mesh::Draw(Shader shader)
{
	// Bind appropriate textures
	GLuint diffuseNr = 1;
	GLuint specularNr = 1;
	GLuint reflectionNr = 1;

	for (GLuint i = 0; i < this->m_textures.size(); i++)
	{
		// Activate proper texture unit before binding
		glActiveTexture(GL_TEXTURE0 + i); 

		std::stringstream ss;
		string number;
		string name = this->m_textures[i].type;

		if (name == "texture_diffuse")
			ss << diffuseNr++; 
		else if (name == "texture_specular")
			ss << specularNr++;
		else if (name == "texture_reflection")
			ss << reflectionNr++;
		number = ss.str();

		// Setting the sampler to the correct texture unit
		shader.SetUniform((name + number).c_str(), i);

		// Unbind the texture
		glBindTexture(GL_TEXTURE_2D, this->m_textures[i].id);
	}

	shader.SetUniform("material.shininess", 16.0f);

	// Draw mesh
	glBindVertexArray(this->m_VAO);
	glDrawElements(GL_TRIANGLES, this->m_indices.size(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	// Always good practice to set everything back to defaults once configured.
	for (GLuint i = 0; i < this->m_textures.size(); i++)
	{
		glActiveTexture(GL_TEXTURE0 + i);
		glBindTexture(GL_TEXTURE_2D, 0);
	}
}

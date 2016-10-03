#ifndef MESH_H
#define MESH_H

#include "config.h"

// Assimp
#include "assimp/Importer.hpp"
#include "assimp/scene.h"
#include "assimp/postprocess.h"

#include "shader.h"

// Structure to hold "vertex" data
struct Vertex {
	// Position
	vec3 position;
	// Normal
	vec3 normal;
	// TexCoords
	vec2 texCoords;
};

// Structure to hold "texture" data
struct Texture {
	GLuint id;
	string type;
	aiString path;
};

class Mesh {
public:
	// Constructors

	Mesh(vector<Vertex> vertices, vector<GLuint> indices, vector<Texture> textures);

	// Methods
	
	void Render(Shader shader);

	// Member Variables

	vector<Vertex> m_vertices;
	vector<GLuint> m_indices;
	vector<Texture> m_textures;

private:
	// Member Variables

	GLuint			m_VAO;			// Vertex Attribute Object
	GLuint			m_VBO;			// Vertex Buffer Object
	GLuint			m_EBO;			// Element Buffer Object

	//  Methods

	void SetupMesh();
};

#endif // MESH_H
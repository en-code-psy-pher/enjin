#pragma once

#include "config.h"

// Assimp
#include "assimp/Importer.hpp"
#include "assimp/scene.h"
#include "assimp/postprocess.h"

#include "shader.h"

struct Vertex {
	// Position
	vec3 position;
	// Normal
	vec3 normal;
	// TexCoords
	vec2 texCoords;
};

struct Texture {
	GLuint id;
	string type;
	aiString path;
};

class Mesh {
public:
	vector<Vertex> m_vertices;
	vector<GLuint> m_indices;
	vector<Texture> m_textures;

	// Constructor
	Mesh(vector<Vertex> vertices, vector<GLuint> indices, vector<Texture> textures);

	// Destructor
	~Mesh();

	// Functions
	void Draw(Shader shader);

private:
	GLuint m_VAO, m_VBO, m_EBO;

	//  Functions 
	void SetupMesh();
};
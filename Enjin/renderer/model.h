#pragma once

// SOIL Lib
#include "SOIL.h"

#include "mesh.h"

class Model
{
public:
	// Constructor
	Model();
	Model(GLchar* path);

	// Destructor
	~Model();

	// Functions
	void Draw(Shader shader);

private:
	//  Functions
	void LoadModel(const string path);
	void ProcessNode(const aiNode* node, const aiScene* scene);
	Mesh ProcessMesh(const aiMesh* mesh, const aiScene* scene);
	GLint TextureFromFile(const char* path, string directory);
	vector<Texture> LoadMaterialTextures(const aiMaterial* mat, const aiTextureType type, const string typeName);

	vector<Mesh> m_meshes;
	string m_directory;
	vector<Texture> m_textures_loaded;	// Stores all the textures loaded so far, optimization to make sure textures aren't loaded more than once.
};


#ifndef MODEL_H
#define MODEL_H

// SOIL Lib
#include "SOIL.h"

#include "mesh.h"

class Model
{
public:
	// Constructors

	Model();						// Default Constructor
	Model(GLchar* path);			// Parameter Constructor

	// Methods

	void Render(Shader shader);		// Render the model

private:
	//  Methods

	void LoadModel(const string path);
	void ProcessNode(const aiNode* node, const aiScene* scene);
	Mesh ProcessMesh(const aiMesh* mesh, const aiScene* scene);
	GLint TextureFromFile(const char* path, string directory);
	vector<Texture> LoadMaterialTextures(const aiMaterial* mat, const aiTextureType type, const string typeName);

	// Member Variables

	vector<Mesh>		m_meshes;
	string				m_directory;
	vector<Texture>		m_textures_loaded;		// Stores all the textures loaded so far, optimization to make sure textures aren't loaded more than once.
};

#endif // MODEL_H
#ifndef GAME_H
#define GAME_H

#include "config.h"

#include "input.h"
#include "camera.h"
#include "shader.h"
#include "pointLight.h"
#include "directionalLight.h"
#include "spotLight.h"
#include "model.h"
#include "texture2D.h"

static const int k_N_POINT_LIGHTS = 4;

class Game
{
public:
	// Constructors

	Game();																	// Default Constructor
	Game(const Input& input, const GLfloat width, const GLfloat height);	// Parameter Constructor
	
	~Game();																// Destructor

	// Methods

	void Initialize();														// Initialize game app
	void Update();															// Update game app
	void Render();															// Render game app

private:
	// Member Variables
	GLfloat				m_width;
	GLfloat				m_height;

	Camera				m_mainCamera;

	Input				m_input;

	DirectionalLight	m_lightDirectional;
	vector<PointLight>	m_lightPoints;
	SpotLight			m_lightSpot;

	Model				m_terrain;
	Model				m_nanosuit;

	Shader				m_shaderSceneLighting;
	Shader				m_shaderLamp;
	
	
	/* Test Variables */
	GLuint				m_lightVAO;
	GLuint				m_lightVBO;

	Shader				m_testShader;

	mat4				m_model;
	mat4				m_normal;
	mat4				m_projection;
	mat4				m_view;
	mat4				m_mvp;
};

#endif // GAME_H
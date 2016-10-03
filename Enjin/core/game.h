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

	Game();						// Default Constructor
	Game(const Input& input);	// Parameter Constructor
	
	~Game();					// Destructor

	// Methods

	void Initialize();			// Initialize game app
	void Update();				// Update game app
	void Render();				// Render game app

private:
	// Member Variables

	Camera				m_mainCamera;

	Input				m_input;

	DirectionalLight	m_lightDirectional;
	vector<PointLight>	m_lightPoints;
	SpotLight			m_lightSpot;

	Model				m_terrain;
	Model				m_nanosuit;

	Shader				m_shaderSceneLighting;
	Shader				m_shaderLamp;
};

#endif // GAME_H
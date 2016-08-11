#pragma once

#include "config.h"

#include "input.h"
#include "camera.h"
#include "shader.h"
#include "pointLight.h"
#include "directionalLight.h"
#include "spotLight.h"
#include "model.h"
#include "texture2D.h"

#define N_POINT_LIGHTS 4

class Game
{
public:
	// Constructor
	Game();
	Game(const Input& input);

	// Destructor
	~Game();

	// Inherited Virutal Functions
	void Initialize();
	void Update(float deltaTime);
	void Render();

private:
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


#include "game.h"

Game::Game()
{
}

Game::Game(const Input& input)
	: m_input(input)
{
	this->Initialize();
}

void Game::Initialize()
{
	m_mainCamera = Camera();

	m_lightDirectional = DirectionalLight(vec3(-0.2f, -1.0f, -0.3f), vec3(0.05f), vec3(0.4f), vec3(1.0f));

	m_lightPoints.reserve(N_POINT_LIGHTS * sizeof(PointLight));

	vec3 pointLightPositions[N_POINT_LIGHTS] = {
													vec3(2.3f, 1.6f, -2.0f),
													vec3(-2.3f, 0.0f, -1.0f),
													vec3(0.3f, -1.6f, -2.0f),
													vec3(8.3f, 0.6f, -3.0f)
												};

	for (size_t i = 0; i < N_POINT_LIGHTS; ++i)
		m_lightPoints.push_back(PointLight(pointLightPositions[i], 1.0f, 0.009f, 0.0032f, vec3(0.05f), vec3(1.0f), vec3(1.0f)));

	m_lightSpot = SpotLight(vec3(0.0f, 10.0f, 0.0f), vec3(0.0f, -1.0f, 0.0f), 1.0f, 0.009f, 0.0032f, vec3(0.0f), vec3(1.0f), vec3(1.0f), glm::cos(glm::radians(12.5f)), glm::cos(glm::radians(15.0f)));

	m_terrain = Model("assets/models/terrain/terrain.obj");
	m_nanosuit = Model("assets/models/nanosuit/nanosuit.obj");

	m_shaderSceneLighting = Shader("assets/shaders/sceneLighting.vs", "shaders/sceneLighting.fs");
	m_shaderLamp = Shader("assets/shaders/lamp.vs", "shaders/lamp.fs");

	// Calculate Normal Matrix for models => Normal = mat3(transpose(inverse(model))) * normal;

	// Set uniforms for shaders
}

void Game::Update(float deltaTime)
{
}

void Game::Render()
{
	// Clear the colorbuffer
	glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

Game::~Game()
{
}
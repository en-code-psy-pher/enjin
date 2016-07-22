#include "game.h"

Game::Game(Camera& camera, Input& input)
	: m_mainCamera(camera), m_input(input)
{
}

Game::~Game()
{
}

void Game::Initialize()
{
}

void Game::Update(float deltaTime)
{
	// Camera controls
	if (m_input.m_keys[GLFW_KEY_W])
		m_mainCamera.ProcessKeyboard(FORWARD, deltaTime);
	if (m_input.m_keys[GLFW_KEY_S])
		m_mainCamera.ProcessKeyboard(BACKWARD, deltaTime);
	if (m_input.m_keys[GLFW_KEY_A])
		m_mainCamera.ProcessKeyboard(LEFT, deltaTime);
	if (m_input.m_keys[GLFW_KEY_D])
		m_mainCamera.ProcessKeyboard(RIGHT, deltaTime);
}

void Game::Render()
{
}

#pragma once

#include "config.h"

#include "input.h"

class Game
{
public:
	// Constructor
	Game(Camera& camera, Input& input);

	// Destructor
	~Game();

	// Inherited Functions
	void Initialize();
	void Update(float deltaTime);
	void Render();

private:
	Camera	m_mainCamera;

	Input	m_input;
};


#pragma once

#include "config.h"

class Scene
{
public:
	Scene();
	~Scene();

	// Functions
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;

protected:
};


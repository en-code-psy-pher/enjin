#ifndef GAME_H
#define GAME_H

#include "config.h"

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
	Game(const GLfloat& width, const GLfloat& height);						// Parameter Constructor
	
	~Game();																// Destructor

	// Methods
	void HandleKeyboardCallblack(GLFWwindow * window, int key,				// Handle keyboard callbacks
								 int scancode, int action, int mode);

	void Initialize();														// Initialize game app
	void Update();															// Update game app
	void Render();															// Render game app

private:
	// Member 
	bool				m_keys[1024];

	GLfloat				m_width;
	GLfloat				m_height;

	Camera				m_mainCamera;

	DirectionalLight	m_lightDirectional;
	vector<PointLight>	m_lightPoints;
	SpotLight			m_lightSpot;

	Model				m_teapot;

	Shader				m_teapotShader;

	float				m_explodeDelta;
	float				m_angle;

	mat4				m_model;
	mat4				m_normal;
	mat4				m_projection;
	mat4				m_view;
	mat4				m_mvp;

	void RenderTeapot();
};

#endif // GAME_H
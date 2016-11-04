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

static const int k_N_POINT_LIGHTS = 5;

class Game
{
public:
	// Constructors

	Game();																		// Default Constructor
	Game(const GLfloat& width, const GLfloat& height);							// Parameter Constructor
	
	~Game();																	// Destructor

	// Methods
	void HandleKeyboardCallblack(GLFWwindow * window, int key,					// Handle keyboard callbacks
								 int scancode, int action, int mode);
	void HandleMouseCallback(GLFWwindow* window, double xpos, double ypos);		// Handle mouse callbacks

	void Initialize();															// Initialize game app
	void Update();																// Update game app
	void Render();																// Render game app

private:
	// Member Variables

	bool				m_keys[1024];
	bool				m_firstMouse;

	float				m_explodeDelta;
	float				m_angle;

	mat4				m_model;
	mat4				m_normal;
	mat4				m_projection;
	mat4				m_view;
	mat4				m_mvp;

	GLuint				m_lampVAO;
	GLuint				m_boxVAO;
	GLuint				m_boxVBO;

	GLfloat				m_lastXPos;
	GLfloat				m_lastYPos;
	GLfloat				m_width;
	GLfloat				m_height;

	Camera				m_mainCamera;

	Texture2D			m_texBox;

	Model				m_terrain;
	Model				m_teapot;

	Shader				m_lampShader;
	Shader				m_terrainShader;
	Shader				m_explodeShader;
	Shader				m_rigidBoxShader;

	DirectionalLight	m_lightDirectional;
	vector<PointLight>	m_lightPoints;
	SpotLight			m_lightSpot;

	GLuint CreateBoxMesh(float size);
	void RenderRigidBoxes();
	void RenderLamps();
	void RenderTerrain();
	void RenderExplodingTeapot();
	void SetLightUniforms(Shader shader);
};

#endif // GAME_H
#include "game.h"

// Default Constructor
Game::Game()
{
}

// Parameter Constructor
Game::Game(const GLfloat width, const GLfloat height)
	: m_width(width), m_height(height)

{
	Initialize();
}

// Destructor
Game::~Game()
{
}

// Intialize the game
void Game::Initialize()
{
	m_mainCamera = Camera();

	//m_lightDirectional = DirectionalLight(vec3(-0.2f, -1.0f, -0.3f), vec3(0.05f), vec3(0.4f), vec3(1.0f));

	//m_lightPoints.reserve(k_N_POINT_LIGHTS * sizeof(PointLight));

	//vec3 pointLightPositions[k_N_POINT_LIGHTS] = {
	//												vec3(2.3f, 1.6f, -2.0f),
	//												vec3(-2.3f, 0.0f, -1.0f),
	//												vec3(0.3f, -1.6f, -2.0f),
	//												vec3(8.3f, 0.6f, -3.0f)
	//											};

	//for (size_t i = 0; i < k_N_POINT_LIGHTS; ++i)
	//	m_lightPoints.push_back(PointLight(pointLightPositions[i], 1.0f, 0.009f, 0.0032f, vec3(0.05f), vec3(1.0f), vec3(1.0f)));

	//m_lightSpot = SpotLight(vec3(0.0f, 10.0f, 0.0f), vec3(0.0f, -1.0f, 0.0f), 1.0f, 0.009f, 0.0032f, vec3(0.0f), vec3(1.0f), vec3(1.0f), glm::cos(glm::radians(12.5f)), glm::cos(glm::radians(15.0f)));

	// Optimize Model Mesh class
//	m_terrain = Model("assets/models/terrain/terrain.obj");
//	m_nanosuit = Model("assets/models/nanosuit/nanosuit.obj");

	m_testShader = Shader("assets/shaders/test.vs", "assets/shaders/test.fs");
	
	// Cube 
	GLfloat vertices[] = {
		// Positions          // Normals           // Texture Coords
		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,
		0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  0.0f,
		0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
		0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,

		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
		0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  0.0f,
		0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
		0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,

		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
		-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
		-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,

		0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
		0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
		0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
		0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
		0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
		0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,

		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,
		0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  1.0f,
		0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
		0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,

		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f,
		0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  1.0f,
		0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
		0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
		-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  0.0f,
		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f
	};

	glGenVertexArrays(1, &m_lightVAO);
	glGenBuffers(1, &m_lightVBO);
	glBindBuffer(GL_ARRAY_BUFFER, m_lightVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	
	glBindVertexArray(m_lightVAO);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GL_FLOAT), (GLvoid*)0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GL_FLOAT), (GLvoid*)(3 * sizeof(GL_FLOAT)));
		glEnableVertexAttribArray(1);

		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GL_FLOAT), (GLvoid*)(6 * sizeof(GL_FLOAT)));
		glEnableVertexAttribArray(2);
	glBindVertexArray(0);

	m_projection = m_mainCamera.GetProjectionMatrix();
}

// Update the game
void Game::Update()
{
	m_view = m_mainCamera.GetViewMatrix();
}

// Render the game
void Game::Render()
{
	// Clear the colorbuffer
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glUseProgram(m_testShader.GetProgram());

	glBindVertexArray(m_lightVAO);
		// Load Identity Matrix
		m_model = mat4();

		// Translate to origin
		m_model = glm::translate(m_model, vec3(0.0f, 0.0f, 0.0f));
		m_model = glm::rotate(m_model, 45.0f, vec3(1.0f, 0.0f, 0.0f));
		int modelLoc = glGetUniformLocation(m_testShader.GetProgram(), "_modelMat");
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(m_model));
		
		// Calculate Model View Projection Matrix mvp => projetction * view * model
		m_mvp = m_projection * m_view * m_model;
		int mvpLoc = glGetUniformLocation(m_testShader.GetProgram(), "_mvpMat");
		glUniformMatrix4fv(mvpLoc, 1, GL_FALSE, glm::value_ptr(m_mvp));

		// Calculate Normal Matrix for models Normal => mat3(transpose(inverse(model)))
		m_normal = glm::inverse(m_model);
		m_normal = glm::transpose(m_normal);
		int normalLoc = glGetUniformLocation(m_testShader.GetProgram(), "_normalMat");
		glUniformMatrix4fv(normalLoc, 1, GL_FALSE, glm::value_ptr(m_normal));
		glDrawArrays(GL_TRIANGLES, 0, 36);
	glBindVertexArray(0);

	glUseProgram(0);
}

// Handle keyboard callbacks
void Game::HandleKeyboardCallblack(GLFWwindow * window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);

	if (key >= 0 && key < 1024)
	{
		if (action == GLFW_PRESS)
			m_keys[key] = true;
		else if (action == GLFW_RELEASE)
			m_keys[key] = false;
	}
}

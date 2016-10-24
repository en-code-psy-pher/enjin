#include "game.h"

// Default Constructor
Game::Game()
{
}

// Parameter Constructor
Game::Game(const GLfloat& width, const GLfloat& height)
	: m_width(width), m_height(height)

{
	m_mainCamera = Camera(m_width, m_height);

	Initialize();
}

// Destructor
Game::~Game()
{
}

// Intialize the game
void Game::Initialize()
{
	// Optimize Model Mesh class
	m_teapot = Model("assets/models/teapot.obj");

	m_testShader = Shader("assets/shaders/test.vs", "assets/shaders/test.fs");
	
	m_projection = m_mainCamera.GetProjectionMatrix();

	m_testShader.Use();

	m_lightDirectional = DirectionalLight(vec3(-0.2f, -1.0f, -0.3f), vec3(1.0f, 0.0f, 0.0f), vec3(1.0f, 0.4f, 0.4f), vec3(1.0f, 1.0f, 1.0f));

	GLint location = glGetUniformLocation(m_testShader.GetProgram(), "eyePos");
	glUniform3f(location, m_mainCamera.GetPositon().x, m_mainCamera.GetPositon().y, m_mainCamera.GetPositon().z);

	location = glGetUniformLocation(m_testShader.GetProgram(), "directionalLight.direction");
	glUniform3f(location, m_lightDirectional.GetDirection().x, m_lightDirectional.GetDirection().y, m_lightDirectional.GetDirection().z);

	location = glGetUniformLocation(m_testShader.GetProgram(), "directionalLight.ambient");
	glUniform3f(location, m_lightDirectional.GetAmbient().x, m_lightDirectional.GetAmbient().y, m_lightDirectional.GetAmbient().z);

	location = glGetUniformLocation(m_testShader.GetProgram(), "directionalLight.diffuse");
	glUniform3f(location, m_lightDirectional.GetDiffuse().x, m_lightDirectional.GetDiffuse().y, m_lightDirectional.GetDiffuse().z);

	location = glGetUniformLocation(m_testShader.GetProgram(), "directionalLight.specular");
	glUniform3f(location, m_lightDirectional.GetSpecular().x, m_lightDirectional.GetSpecular().y, m_lightDirectional.GetSpecular().z);

	m_lightPoints.reserve(k_N_POINT_LIGHTS * sizeof(PointLight));

	vec3 pointLightPositions[k_N_POINT_LIGHTS] = {
													vec3(2.3f, 1.6f, -2.0f),
													vec3(-2.3f, 0.0f, -1.0f),
													vec3(0.3f, -1.6f, -2.0f),
													vec3(8.3f, 0.6f, -3.0f)
												};

	for (unsigned int i = 0; i < k_N_POINT_LIGHTS; ++i)
		m_lightPoints.push_back(PointLight(pointLightPositions[i], 1.0f, 0.009f, 0.0032f, vec3(0.05f, 0.05f, 0.05f), vec3(0.4f, 0.4f, 1.0f), vec3(1.0f, 1.0f, 1.0f)));

	string pointLightUniformName = "";
	for (unsigned int i = 0; i < k_N_POINT_LIGHTS; ++i)
	{
		pointLightUniformName = "pointLights[" + std::to_string(i) + "]";

		location = glGetUniformLocation(m_testShader.GetProgram(), (pointLightUniformName + ".position").c_str());
		glUniform3f(location, m_lightPoints[i].GetPosition().x, m_lightPoints[i].GetPosition().y, m_lightPoints[i].GetPosition().z);

		location = glGetUniformLocation(m_testShader.GetProgram(), (pointLightUniformName + ".ambient").c_str());
		glUniform3f(location, m_lightPoints[i].GetAmbient().x, m_lightPoints[i].GetAmbient().y, m_lightPoints[i].GetAmbient().z);

		location = glGetUniformLocation(m_testShader.GetProgram(), (pointLightUniformName + ".diffuse").c_str());
		glUniform3f(location, m_lightPoints[i].GetDiffuse().x, m_lightPoints[i].GetDiffuse().y, m_lightPoints[i].GetDiffuse().z);

		location = glGetUniformLocation(m_testShader.GetProgram(), (pointLightUniformName + ".specular").c_str());
		glUniform3f(location, m_lightPoints[i].GetSpecular().x, m_lightPoints[i].GetSpecular().y, m_lightPoints[i].GetSpecular().z);

		location = glGetUniformLocation(m_testShader.GetProgram(), (pointLightUniformName + ".constant").c_str());
		glUniform1f(location, m_lightPoints[i].GetConstant());

		location = glGetUniformLocation(m_testShader.GetProgram(), (pointLightUniformName + ".linear").c_str());
		glUniform1f(location, m_lightPoints[i].GetLinear());

		location = glGetUniformLocation(m_testShader.GetProgram(), (pointLightUniformName + ".quadratic").c_str());
		glUniform1f(location, m_lightPoints[i].GetQuadratic());
	}

	m_lightSpot = SpotLight(vec3(0.0f, 10.0f, 0.0f), vec3(0.0f, -1.0f, 0.0f), 1.0f, 0.009f, 0.0032f, vec3(0.0f, 0.0f, 0.0f), vec3(1.0f, 1.0f, 1.0f), vec3(1.0f, 1.0f, 1.0f), glm::cos(glm::radians(12.5f)), glm::cos(glm::radians(15.0f)));

	location = glGetUniformLocation(m_testShader.GetProgram(), "spotLight.position");
	glUniform3f(location, m_lightSpot.GetPosition().x, m_lightSpot.GetPosition().y, m_lightSpot.GetPosition().z);

	location = glGetUniformLocation(m_testShader.GetProgram(), "spotLight.direction");
	glUniform3f(location, m_lightSpot.GetDirection().x, m_lightSpot.GetDirection().y, m_lightSpot.GetDirection().z);

	location = glGetUniformLocation(m_testShader.GetProgram(), "spotLight.ambeint");
	glUniform3f(location, m_lightSpot.GetAmbient().x, m_lightSpot.GetAmbient().y, m_lightSpot.GetAmbient().z);

	location = glGetUniformLocation(m_testShader.GetProgram(), "spotLight.diffuse");
	glUniform3f(location, m_lightSpot.GetDiffuse().x, m_lightSpot.GetDiffuse().y, m_lightSpot.GetDiffuse().z);

	location = glGetUniformLocation(m_testShader.GetProgram(), "spotLight.specular");
	glUniform3f(location, m_lightSpot.GetSpecular().x, m_lightSpot.GetSpecular().y, m_lightSpot.GetSpecular().z);

	location = glGetUniformLocation(m_testShader.GetProgram(), "spotLight.constant");
	glUniform1f(location, m_lightSpot.GetConstant());

	location = glGetUniformLocation(m_testShader.GetProgram(), "spotLight.linear");
	glUniform1f(location, m_lightSpot.GetLinear());

	location = glGetUniformLocation(m_testShader.GetProgram(), "spotLight.quadratic");
	glUniform1f(location, m_lightSpot.GetQuadratic());

	location = glGetUniformLocation(m_testShader.GetProgram(), "spotLight.cutOff");
	glUniform1f(location, m_lightSpot.GetCutoff());

	location = glGetUniformLocation(m_testShader.GetProgram(), "spotLight.outerCutOff");
	glUniform1f(location, m_lightSpot.GetOuterCutoff());
}

// Update the game
void Game::Update()
{
	m_mainCamera.Update();
	m_view = m_mainCamera.GetViewMatrix();
}

// Render the game
void Game::Render()
{
	m_view = m_mainCamera.GetViewMatrix();

	// Clear the colorbuffer
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	RenderTeapot();
}

void Game::RenderTeapot()
{
	glUseProgram(m_testShader.GetProgram());

	// Load Identity Matrix
	m_model = mat4();

	// Translate to origin
	m_model = glm::translate(m_model, vec3(0.0f, 0.0f, 0.0f));
	//	m_model = glm::rotate(m_model, 45.0f, vec3(1.0f, 0.0f, 0.0f));
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
	m_teapot.Render(m_testShader);

	glUseProgram(0);
}

// Handle keyboard callbacks
void Game::HandleKeyboardCallblack(GLFWwindow * window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);

	if (key == GLFW_KEY_W || key == GLFW_KEY_UP)
		m_mainCamera.m_position += 0.05f * m_mainCamera.m_fowardDirection;
	if (key == GLFW_KEY_S || key == GLFW_KEY_DOWN)
		m_mainCamera.m_position -= 0.05f * m_mainCamera.m_fowardDirection;
	if (key == GLFW_KEY_A || key == GLFW_KEY_LEFT)
		m_mainCamera.m_position -= 0.05f * glm::normalize(glm::cross(m_mainCamera.m_fowardDirection, m_mainCamera.m_up));
	if (key == GLFW_KEY_D || key == GLFW_KEY_RIGHT)
		m_mainCamera.m_position += 0.05f * glm::normalize(glm::cross(m_mainCamera.m_fowardDirection, m_mainCamera.m_up));

	if (key >= 0 && key < 1024)
	{
		if (action == GLFW_PRESS)
			m_keys[key] = true;
		else if (action == GLFW_RELEASE)
			m_keys[key] = false;
	}
}

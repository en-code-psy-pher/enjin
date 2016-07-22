#include "config.h"

#include "input.h"
#include "game.h"
#include "camera.h"

// Window
GLFWwindow* window;

// Deltatime
GLfloat deltaTime = 0.0f;
GLfloat lastFrame = 0.0f;

GLint width = 800;
GLint height = 600;

// Main Camera
Camera mainCamera;

// Input
Input input(width, height, mainCamera);

// Game
Game game(mainCamera, input);

// Call back functions
static void KeyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	input.HandleKeyboardCallblack(window, key, scancode, action, mode);
}

void MouseCallback(GLFWwindow* window, double xpos, double ypos)
{
	input.HandleMouseCallblack(xpos, ypos);
}

static void ErrorCallback(int error, const char* description)
{
	cout << description << endl;
}

int main()
{
	// Initialize GLFW
	if (!glfwInit())
		exit(EXIT_FAILURE);

	// Set GLFW error callback
	glfwSetErrorCallback(ErrorCallback);

	// Set OpenGL Options in GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	glfwWindowHint(GLFW_RED_BITS, 8);
	glfwWindowHint(GLFW_GREEN_BITS, 8);
	glfwWindowHint(GLFW_BLUE_BITS, 8);
	glfwWindowHint(GLFW_DEPTH_BITS, 8);
	glfwWindowHint(GLFW_DOUBLEBUFFER, true);

	// Create and set window
	window = glfwCreateWindow(width, height, "Codex Enjin 0.0", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
		return -1;
	}

	glfwMakeContextCurrent(window);

	// Set Callbacks
	glfwSetKeyCallback(window, KeyboardCallback);
	glfwSetCursorPosCallback(window, MouseCallback);

	// Hide the cursor
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	// Initialize GLEW to setup the OpenGL Function pointers
	glewExperimental = GL_TRUE;
	GLenum glewError{ glewInit() };
	if (glewError != GLEW_OK)
	{
		exit(EXIT_FAILURE);
	}

	// Define the viewport dimensions
	glViewport(0, 0, width, height);

	// OpenGL options
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	game.Initialize();

	while (!glfwWindowShouldClose(window))
	{
		// Calculate deltatime of current frame
		double currentFrame = glfwGetTime();
		deltaTime = (GLfloat)currentFrame - lastFrame;
		lastFrame = (GLfloat)currentFrame;

		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();

		game.Update(deltaTime);

		// Clear the colorbuffer
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		game.Render();

		glfwSwapBuffers(window);
	}

	// Cleanup

	glfwDestroyWindow(window);

	glfwTerminate();
	exit(EXIT_SUCCESS);
}
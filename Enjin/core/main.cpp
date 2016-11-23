#include "config.h"

#undef UNICODE
#include <windows.h>

#include "game.h"
#include "camera.h"

// Window Dimensions
GLfloat				width;
GLfloat				height;

// Window
GLFWwindow *		window;

// Game
Game				game;

static void KeyboardCallblack(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	game.HandleKeyboardCallblack(window, key, scancode, action, mode);
}

static void MouseCallblack(GLFWwindow* window, double xpos, double ypos)
{
	game.HandleMouseCallback(window, xpos, ypos);
}

// GLFW Error call back
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

	width = 800.0f;
	height = 600.0f;

	// Create and set window
	window = glfwCreateWindow((int)width, (int)height, "Enjin 0.0", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
		return -1;
	}

	glfwMakeContextCurrent(window);

	// Set Callbacks
	glfwSetKeyCallback(window, KeyboardCallblack);
	glfwSetCursorPosCallback(window, MouseCallblack);

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
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);

	// OpenGL options
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	game = Game((GLfloat)width, (GLfloat)height);

	DWORD lastTime = timeGetTime();

	while (!glfwWindowShouldClose(window))
	{
		// Pause kSleepTimeMs milliseconds

		const DWORD kSleepTimeMs = 20;
		const DWORD currentTime = timeGetTime();
		const DWORD timeSinceLast = currentTime - lastTime;

		if (timeSinceLast < kSleepTimeMs)
		{
			Sleep(kSleepTimeMs - timeSinceLast);
		}

		lastTime = currentTime;

		game.Render();

		glfwPollEvents();

		game.Update();
		
		glfwSwapBuffers(window);
	}

	// Cleanup
	glfwDestroyWindow(window);

	glfwTerminate();
	exit(EXIT_SUCCESS);
}
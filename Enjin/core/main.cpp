#include "config.h"

#undef UNICODE
#include <windows.h>

#include "input.h"
#include "game.h"
#include "camera.h"

int width;
int height;

// Window
GLFWwindow* window;

// Input
Input input;

// Game
Game game;

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

	width = 800;
	height = 600;

	// Create and set window
	window = glfwCreateWindow(width, height, "Enjin 0.0", NULL, NULL);

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
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);

	// OpenGL options
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	input = Input((GLfloat)width, (GLfloat)height);
	game = Game(input, (GLfloat)width, (GLfloat)height);

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
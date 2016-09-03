#include <time.h>

#include "config.h"

#include "input.h"
#include "game.h"
#include "camera.h"

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

double ClockToMilliseconds(clock_t ticks) 
{
	return (ticks / (double)CLOCKS_PER_SEC) / 1000.0;
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
	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Enjin 0.0", NULL, NULL);

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
	glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

	// OpenGL options
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	game = Game(input);
	
	time_t beginTime; //time at the start of the loop
	time_t currentTime; //time when checking for a one-second interval
	
	double frames = 0; //number of times passed through the loop

	time(&beginTime); //sets begin_time

	while (!glfwWindowShouldClose(window))
	{
		frames++;
		
		time(&currentTime);

		float deltaTime = currentTime - beginTime;

		game.Render();

		glfwPollEvents();

		game.Update(deltaTime);
		
		glfwSwapBuffers(window);

		if (difftime(currentTime, beginTime) >= 1.0)
		{
			cout << "FPS: " << frames << endl;

			frames = 0;
			
			time(&beginTime); 
		}
	}

	// Cleanup

	glfwDestroyWindow(window);

	glfwTerminate();
	exit(EXIT_SUCCESS);
}
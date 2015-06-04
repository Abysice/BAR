#include "BAREngine.h"
#include <Windows.h>

Engine * Engine::instance = 0;
const GLuint WIDTH = 800, HEIGHT = 600;


void Engine::Init(void)
{
	#if DEBUG_MODE
		std::cout << "Starting Engine" << std::endl;
	#else
		FreeConsole(); //hide the console
	#endif

	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	window = glfwCreateWindow(WIDTH, HEIGHT, "BAR Engine", nullptr, nullptr);
	glfwMakeContextCurrent(window);

	if (window == NULL)
	{
		#if DEBUG_MODE
			std::cout << "Failed to create GLFW window" << std::endl;
		#endif

		glfwTerminate();
		return;
	}
	
	//setup GLFW callbacks
	//glfwSetKeyCallback(window, key_callback);

	// Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		#if DEBUG_MODE
			std::cout << "Failed to initialize GLEW" << std::endl;
		#endif
		return;
	}

	glViewport(0, 0, WIDTH, HEIGHT);

	// Main Engine Loop
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents(); // Check if any events have been activiated 
		
		Render();
		
		
	}

	glfwTerminate(); // Terminate GLFW
}


void Engine::Render(void)
{
	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(window);
}

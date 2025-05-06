#include"Misc.h"

int main()
{
	if (!glfwInit())
	{
		std::cerr << "Failed to initialize glfw\n";
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	std::pair <int, int> windowRes{ 1280, 960 };
	GLFWwindow* window;
	window = glfwCreateWindow(windowRes.first, windowRes.second, "GKOM", NULL, NULL);

	//window = glfwCreateWindow(1280, 960, "GKOM", NULL, NULL);

	if (window == NULL)
	{
		std::cerr << "Window not created\n";
		glfwTerminate();
		return -2;
	}

	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK)
	{
		std::cerr << "Failed to initialize glew\n";
		glfwTerminate();
		return -3;
	}

	glClearColor(0.1f, 0.2f, 0.3f, 0.0f);
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
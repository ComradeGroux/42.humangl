#include "opengl_error.h"


#include "init.h"

#include <iostream>

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	GLFWwindow*	window;
	try
	{
		window = createWindow();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	int	width, height;
	glfwGetFramebufferSize(window, &width, &height);
	cgl(glViewport(0, 0, width, height));
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();

		glfwSwapBuffers(window);
	}

	clearOpenGLInstance(window);
	return 0;
}

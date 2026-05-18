#include "opengl_error.h"

#include "init.hpp"
#include "matrix.hpp"
#include "Animator.hpp"

#include <iostream>

void	drawBone(const matrix::mat4& matrice)
{
	(void)matrice;
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	GLFWwindow*	window;
	BoneNode*	human;
	try
	{
		window = createWindow();
		human = createHuman(drawBone);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	Animator	animator(human);
	animator.renderAnimation(0.0f);

	(void)window;
	int	width, height;
	glfwGetFramebufferSize(window, &width, &height);
	cgl(glViewport(0, 0, width, height));
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();

		glfwSwapBuffers(window);
	}

	clearOpenGLInstance(window);

	delete human;
	return 0;
}

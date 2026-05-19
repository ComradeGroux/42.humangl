#include "opengl_error.h"

#include "init.hpp"
#include "matrix.hpp"
#include "Animator.hpp"
#include "Renderer.hpp"

#include <iostream>

static void	mainLoop(GLFWwindow* window, Animator& anim)
{
	int	width, height;
	glfwGetFramebufferSize(window, &width, &height);
	cgl(glViewport(0, 0, width, height));
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();

		anim.renderAnimation(0.2f);

		glfwSwapBuffers(window);
	}
}

static int	inOpenGLContext(GLFWwindow* window)
{
	BoneNode*	human;
	Renderer	renderer("shader/basic.vert", "shader/basic.frag");
	try
	{
		human = createHuman([&renderer](const matrix::mat4& mat) { renderer.draw(mat); });
		Animator	animator(human);
		mainLoop(window, animator);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	delete human;
	return 0;
}

int	main(void)
{
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

	if (inOpenGLContext(window))
		return 1;

	clearOpenGLInstance(window);
	return 0;
}

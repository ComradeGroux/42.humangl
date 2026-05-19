#include "opengl_error.h"

#include "init.hpp"
#include "matrix.hpp"
#include "Animator.hpp"
#include "Renderer.hpp"

#include <iostream>

static void	mainLoop(GLFWwindow* window, Renderer& renderer, Animator& anim)
{
	int		width, height;
	float	aspectRatio;
	while (!glfwWindowShouldClose(window))
	{
		glfwGetFramebufferSize(window, &width, &height);
		aspectRatio = static_cast<float>(width) / static_cast<float>(height);

		glfwPollEvents();

		cgl(glClearColor(0.529f, 0.808f, 0.922f, 1.0f));
		renderer.setViewProjectionUniform(aspectRatio);
		anim.renderAnimation(0.2f);

		glfwSwapBuffers(window);
	}
}

static int	inOpenGLContext(GLFWwindow* window)
{
	BoneNode*	human;
	Camera		camera(matrix::vec3(0.0f, 0.0f, -0.5f), 0.0f, 0.0f);
	Renderer	renderer(camera, "shader/basic.vert", "shader/basic.frag");
	try
	{
		human = createHuman([&renderer](const matrix::mat4& mat) { renderer.draw(mat); });
		Animator	animator(human);
		mainLoop(window, renderer, animator);
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

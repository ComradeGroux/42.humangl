#include "opengl_error.h"

#include "init.hpp"
#include "matrix.hpp"
#include "Animator.hpp"
#include "Renderer.hpp"

#include <iostream>

static void	mainLoop(GLFWwindow* window, Renderer& renderer, Animator& anim, State& state)
{
	int		width, height;
	float	aspectRatio;
	double	now, lastTime, deltaTime = 0;
	while (!glfwWindowShouldClose(window))
	{
		cgl(glClearColor(0.529f, 0.808f, 0.922f, 1.0f));
		cgl(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));

		glfwGetFramebufferSize(window, &width, &height);
		aspectRatio = static_cast<float>(width) / static_cast<float>(height);
		now = glfwGetTime();
		deltaTime = now - lastTime;
		lastTime = now;

		glfwPollEvents();

		if (state.autorotate)
			renderer.updateCam(deltaTime);
		if (state.animation != anim.getActualAnimation())
			anim.chooseAnimation(state.animation);

		renderer.setProjectionUniform(aspectRatio);
		renderer.setCenterUniform();
		anim.renderAnimation(deltaTime);

		glfwSwapBuffers(window);
	}
}

static int	inOpenGLContext(GLFWwindow* window)
{
	BoneNode*	human = nullptr;
	Camera 		camera(4.0f, 0.3f, 0.3f);
	Renderer	renderer(camera, "shader/basic.vert", "shader/basic.frag");
	State		state;
	glfwSetWindowUserPointer(window, &state);
	try
	{
		human = createHuman([&renderer](const matrix::mat4& mat) { renderer.draw(mat); });
		Animator	animator(human);
		mainLoop(window, renderer, animator, state);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		if (human != nullptr)
			delete human;
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

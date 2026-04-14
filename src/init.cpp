#include "glad/glad.h"
#include "init.h"

#include <stdexcept>

static void	initGLAD(GLFWwindow *win)
{
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		clearOpenGLInstance(win);
		throw std::runtime_error("[GLAD] Failed to initialize");
	}
}

GLFWwindow*	createWindow(void)
{
	if (!glfwInit())
		throw std::runtime_error("[GLFW] Failed to initialize");

	glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_DECORATED, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
	glfwWindowHint(GLFW_DOUBLEBUFFER, GL_TRUE);

	GLFWwindow*	win = glfwCreateWindow(800, 600, "HumanGL", NULL, NULL);
	if (!win)
	{
		glfwTerminate();
		throw std::runtime_error("[GLFW] Failed to create window");
	}

	glfwMakeContextCurrent(win);

	initGLAD(win);

	return win;
}

void	clearOpenGLInstance(GLFWwindow *window)
{
	glfwDestroyWindow(window);
	glfwTerminate();
}

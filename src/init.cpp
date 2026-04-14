#include "glad/glad.h"
#include "opengl_error.h"

#include "init.h"

#include <stdexcept>
#include <iostream>

static void	error_cb(int error, const char* description)
{
	std::cerr << "Error " << error << ": " << description << std::endl;
}

static void	debug_cb(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message, const void *userParam)
{
	(void)source;
	(void)type;
	(void)id;
	(void)length;
	(void)userParam;

	if (severity == GL_DEBUG_SEVERITY_NOTIFICATION)
		return;

	const char* severityStr = "UNKNOWN";
	switch (severity)
	{
		case GL_DEBUG_SEVERITY_HIGH:
			severityStr = "HIGH";
			break;
		case GL_DEBUG_SEVERITY_MEDIUM:
			severityStr = "MEDIUM";
			break;
		case GL_DEBUG_SEVERITY_LOW:
			severityStr = "LOW";
			break;
		default:
			break;
	}
	std::cerr << "OpenGL [" << severityStr << "]: " << message << std::endl;
}

static void	key_cb(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	(void)scancode;
	(void)mods;

	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
}

GLFWwindow*	createWindow(void)
{
	if (!glfwInit())
		throw std::runtime_error("[GLFW] Failed to initialize");

	glfwSetErrorCallback(error_cb);

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

	glfwSetKeyCallback(win, key_cb);
	glfwMakeContextCurrent(win);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		clearOpenGLInstance(win);
		throw std::runtime_error("[GLAD] Failed to initialize");
	}

	cgl(glEnable(GL_DEPTH_TEST));
	cgl(glDebugMessageCallback(debug_cb, nullptr));

	return win;
}

void	clearOpenGLInstance(GLFWwindow *window)
{
	glfwDestroyWindow(window);
	glfwTerminate();
}

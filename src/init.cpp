#include "glad/glad.h"
#include "opengl_error.h"
#include "ANSI-color-codes.h"

#include "init.hpp"

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
	std::string	color = WHT;
	switch (severity)
	{
		case GL_DEBUG_SEVERITY_HIGH:
			severityStr = "HIGH";
			color = REDB;
			break;
		case GL_DEBUG_SEVERITY_MEDIUM:
			severityStr = "MEDIUM";
			color = RED;
			break;
		case GL_DEBUG_SEVERITY_LOW:
			severityStr = "LOW";
			color = YEL;
			break;
		default:
			break;
	}
	std::cerr << color << "OpenGL [" << severityStr << "]" << CRESET << ": " << message << std::endl;
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

BoneNode*	createHuman(std::function<void (const matrix::mat4&)> drawFunc)
{
	BoneNode*	root = new BoneNode(nullptr);
	BoneNode*	head = new BoneNode(drawFunc);
	BoneNode*	chest = new BoneNode(drawFunc);
	BoneNode*	upperArmLeft = new BoneNode(drawFunc);
	BoneNode*	lowerArmLeft = new BoneNode(drawFunc);
	BoneNode*	upperArmRight = new BoneNode(drawFunc);
	BoneNode*	lowerArmRight = new BoneNode(drawFunc);
	BoneNode*	upperLegLeft = new BoneNode(drawFunc);
	BoneNode*	lowerLegLeft = new BoneNode(drawFunc);
	BoneNode*	upperLegRight = new BoneNode(drawFunc);
	BoneNode*	lowerLegRight = new BoneNode(drawFunc);

	root->addChild(BoneNode::body_part::CHEST, chest);
	chest->addChild(BoneNode::body_part::HEAD, head);
	chest->addChild(BoneNode::body_part::UPPER_ARM_LEFT, upperArmLeft);
	upperArmLeft->addChild(BoneNode::body_part::LOWER_ARM_LEFT, lowerArmLeft);
	chest->addChild(BoneNode::body_part::UPPER_ARM_RIGHT, upperArmRight);
	upperArmRight->addChild(BoneNode::body_part::LOWER_ARM_RIGHT, lowerArmRight);
	chest->addChild(BoneNode::body_part::UPPER_LEG_LEFT, upperLegLeft);
	upperLegLeft->addChild(BoneNode::body_part::LOWER_LEG_LEFT, lowerLegLeft);
	chest->addChild(BoneNode::body_part::UPPER_LEG_RIGHT, upperLegRight);
	upperLegRight->addChild(BoneNode::body_part::LOWER_LEG_RIGHT, lowerLegRight);

	return root;
}

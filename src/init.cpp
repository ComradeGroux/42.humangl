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

	State*	state = static_cast<State*>(glfwGetWindowUserPointer(window));

	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	else if (key == GLFW_KEY_1 && action == GLFW_PRESS)
		state->animation = Animator::ANIM_IDLE;
	else if (key == GLFW_KEY_2 && action == GLFW_PRESS)
		state->animation = Animator::ANIM_WALK;
	else if (key == GLFW_KEY_3 && action == GLFW_PRESS)
		state->animation = Animator::ANIM_JUMP;
	else if (key == GLFW_KEY_0 && action == GLFW_PRESS)
		state->animation = Animator::ANIM_TPOSE;
	else if (key == GLFW_KEY_R && action == GLFW_PRESS)
		state->autorotate = !(state->autorotate);
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
	matrix::mat4	transform;
	matrix::identity(transform);
	transform = matrix::translate(transform, {0.0f, 0.75f, 0.0f});
	BoneNode*		root = new BoneNode(nullptr, transform);

	matrix::identity(transform);
	transform = matrix::translate(transform, {0.0f, 0.0f, 0.0f});
	transform.scale({0.5f, 1.0f, 0.7f});
	BoneNode*		chest = new BoneNode(drawFunc, transform);

	matrix::identity(transform);
	transform = matrix::translate(transform, {0.0f, 0.775f, 0.0f});
	transform.scale({0.55f, 0.55f, 0.55f});
	BoneNode*		head = new BoneNode(drawFunc, transform);

	matrix::identity(transform);
	transform = matrix::translate(transform, {0.0f, 0.25f, -0.5f});
	transform.scale({0.35f, 0.5f, 0.3f});
	BoneNode*		upperArmLeft = new BoneNode(drawFunc, transform);
	matrix::identity(transform);
	transform = matrix::translate(transform, {0.0f, -0.5f, 0.0f});
	transform.scale({0.35f, 0.5f, 0.3f});
	BoneNode*		lowerArmLeft = new BoneNode(drawFunc, transform);

	matrix::identity(transform);
	transform = matrix::translate(transform, {0.0f, 0.25f, 0.5f});
	transform.scale({0.35f, 0.5f, 0.3f});
	BoneNode*		upperArmRight = new BoneNode(drawFunc, transform);
	matrix::identity(transform);
	transform = matrix::translate(transform, {0.0f, -0.5f, 0.0f});
	transform.scale({0.35f, 0.5f, 0.3f});
	BoneNode*		lowerArmRight = new BoneNode(drawFunc, transform);

	matrix::identity(transform);
	transform = matrix::translate(transform, {0.0f, -0.75f, -0.2f});
	transform.scale({0.35f, 0.5f, 0.3f});
	BoneNode*		upperLegLeft = new BoneNode(drawFunc, transform);
	matrix::identity(transform);
	transform = matrix::translate(transform, {0.0f, -0.5f, 0.0f});
	transform.scale({0.35f, 0.5f, 0.3f});
	BoneNode*		lowerLegLeft = new BoneNode(drawFunc, transform);

	matrix::identity(transform);
	transform = matrix::translate(transform, {0.0f, -0.75f, 0.2f});
	transform.scale({0.35f, 0.5f, 0.3f});
	BoneNode*		upperLegRight = new BoneNode(drawFunc, transform);
	matrix::identity(transform);
	transform = matrix::translate(transform, {0.0f, -0.5f, 0.0f});
	transform.scale({0.35f, 0.5f, 0.3f});
	BoneNode*		lowerLegRight = new BoneNode(drawFunc, transform);

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

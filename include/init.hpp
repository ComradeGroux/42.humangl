#pragma once

#include <GLFW/glfw3.h>

#include "matrix.hpp"
#include "BoneNode.hpp"
#include "Animator.hpp"

struct State {
	bool					autorotate = true;
	Animator::AnimationType	animation = Animator::ANIM_TPOSE;
};

BoneNode*	createHuman(std::function<void (const matrix::mat4&)> drawFunc);

GLFWwindow*	createWindow(void);
void		clearOpenGLInstance(GLFWwindow *window);

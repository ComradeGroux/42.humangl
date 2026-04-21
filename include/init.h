#pragma once

#include <GLFW/glfw3.h>

#include "matrix.hpp"
#include "BoneNode.hpp"

BoneNode*	allocateHuman(std::function<void (const matrix::mat4&)> drawFunc);
void		deleteHuman(BoneNode* torso);

GLFWwindow*	createWindow(void);
void		clearOpenGLInstance(GLFWwindow *window);

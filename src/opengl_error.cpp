#include "opengl_error.h"

#include <iostream>

void	GLClearError()
{
	while (glGetError() != GL_NO_ERROR);
}

void GLGetError(const char *function, const char *file, int line)
{
	while (GLenum error = glGetError())
	{
		std::cerr << "[OpenGL Error] (" << error << ") in " << function << " " << file << " at line " << line << std::endl;
	}
}
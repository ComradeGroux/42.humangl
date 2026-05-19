#include "Renderer.hpp"
#include "opengl_error.h"

#include <fstream>
#include <sstream>
#include <iostream>

Renderer::Renderer(void)
{
	_createVaoVboEbo();
	_isLoaded = false;
}

Renderer::Renderer(const char* vertexPath, const char* fragmentPath)
{
	_createVaoVboEbo();
	_createShader(vertexPath, fragmentPath);
	_isLoaded = true;
}

Renderer::~Renderer(void)
{
	if (_isLoaded)
	{
		cgl(glDeleteProgram(_shader));
	}
	cgl(glDeleteVertexArrays(1, &_vao));
	cgl(glDeleteBuffers(1, &_vbo));
	cgl(glDeleteBuffers(1, &_ebo));
}

void	Renderer::loadShader(const char* vertexPath, const char* fragmentPath)
{
	if (_isLoaded)
	{
		cgl(glDeleteProgram(_shader));
	}

	_createShader(vertexPath, fragmentPath);
	_isLoaded = true;
}

void	Renderer::_createShader(const char* vertexPath, const char* fragmentPath)
{
	GLuint vertex	= _compileShader(vertexPath, GL_VERTEX_SHADER);
	GLuint fragment	= _compileShader(fragmentPath, GL_FRAGMENT_SHADER);

	_shader = glCreateProgram();
	cgl(glAttachShader(_shader, vertex));
	cgl(glAttachShader(_shader, fragment));
	cgl(glLinkProgram(_shader));
	_checkShaderCompilation(_shader, true);

	cgl(glDeleteShader(vertex));
	cgl(glDeleteShader(fragment));

	GLint linked;
	cgl(glGetProgramiv(_shader, GL_LINK_STATUS, &linked));
}

GLuint	Renderer::_compileShader(const char* path, GLenum type) const
{
	std::ifstream	file(path);
	if (!file.is_open())
	{
		std::string	err = "Failed to open shader ";
		err += path;	
		throw std::runtime_error(err);
	}

	std::stringstream	buffer;
	buffer << file.rdbuf();
	std::string	tmp = buffer.str();
	const char*	src = tmp.c_str();

	GLuint	shader = glCreateShader(type);
	cgl(glShaderSource(shader, 1, &src, nullptr));
	cgl(glCompileShader(shader));
	_checkShaderCompilation(shader, false);
	return shader;
}

void	Renderer::_checkShaderCompilation(GLuint shader, bool isProgram) const
{
	GLint	success;

	if (isProgram)
	{
		cgl(glGetProgramiv(shader, GL_LINK_STATUS, &success));
		if (!success)
		{
			GLint	logLength;
			cgl(glGetProgramiv(shader, GL_INFO_LOG_LENGTH, &logLength));
			std::string log(logLength, '\0');
			cgl(glGetProgramInfoLog(shader, logLength, nullptr, &log[0]));
			throw std::runtime_error(log);
		}
	}
	else
	{
		cgl(glGetShaderiv(shader, GL_COMPILE_STATUS, &success));
		if (!success)
		{
			GLint	logLength;
			cgl(glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength));
			std::string log(logLength, '\0');
			cgl(glGetShaderInfoLog(shader, logLength, nullptr, &log[0]));
			throw std::runtime_error(log);
		}
	}
}

void	Renderer::_createVaoVboEbo(void)
{
	cgl(glGenVertexArrays(1, &_vao));
	cgl(glGenBuffers(1, &_vbo));
	cgl(glGenBuffers(1, &_ebo));

	float		vertices[3 * 8] = {
		0, 0, 0,
		0, 0, 1,
		0, 1, 0,
		0, 1, 1,

		1, 0, 0,
		1, 0, 1,
		1, 1, 0,
		1, 1, 1,
	};
	uint32_t	indices[3 * 2 * 6] = {
		0, 1, 2,
		1, 2, 3,

		4, 5, 6,
		5, 6, 7,

		0, 2, 4,
		2, 4, 6,

		1, 3, 5,
		3, 5, 7,

		2, 3, 7,
		3, 7, 6,

		0, 1, 4,
		1, 4, 5
	};

	cgl(glBindVertexArray(_vao));

	cgl(glBindBuffer(GL_ARRAY_BUFFER, _vbo));
	cgl(glBufferData(GL_ARRAY_BUFFER,
					sizeof(vertices),
					vertices,
					GL_STATIC_DRAW));
	cgl(glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0));
	cgl(glEnableVertexAttribArray(0));

	cgl(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo));
	cgl(glBufferData(GL_ELEMENT_ARRAY_BUFFER,
					sizeof(indices),
					indices,
					GL_STATIC_DRAW));

	cgl(glBindVertexArray(0));
}

void	Renderer::draw(const matrix::mat4& matrice)
{
	if (!_isLoaded)
		throw std::runtime_error("There isn't any shader !");

	cgl(glUseProgram(_shader));
	cgl(glUniformMatrix4fv(glGetUniformLocation(_shader, "uMVP_matrix"), 1, GL_FALSE, matrice.data));

	cgl(glBindVertexArray(_vao));
	cgl(glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0));
	cgl(glBindVertexArray(0));
}

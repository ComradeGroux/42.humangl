#pragma once

#include "glad/glad.h"

#include "mat4.hpp"

class Renderer {
	private:
		GLuint	_vao;
		GLuint	_vbo;
		GLuint	_ebo;
		void	_createVaoVboEbo(void);

		GLuint	_shader;
		bool	_isLoaded;
		void	_createShader(const char* vertexPath, const char* fragmentPath);
		GLuint	_compileShader(const char* path, GLenum type) const;
		void	_checkShaderCompilation(GLuint shader, bool isProgram) const;

	public:
		Renderer(void);
		Renderer(const char* vertexPath, const char* fragmentPath);
		~Renderer(void);

		void	loadShader(const char* vertexPath, const char* fragmentPath);
		void	draw(const matrix::mat4& matrice);
};

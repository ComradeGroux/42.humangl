#pragma once

#include "vec4.hpp"

namespace matrix {
	struct mat4 {
		float	data[16];

		mat4(void);
		mat4(const mat4& rhs);
		mat4&	operator=(const mat4& rhs);

		mat4	operator+(const mat4& rhs) const;
		mat4	operator-(const mat4& rhs) const;
		mat4	operator*(const mat4& rhs) const;
		vec4	operator*(const vec4& rhs) const;
		mat4	operator/(const mat4& rhs) const;
	};

	void	identity(mat4& matrice);
	float	determinant(const mat4 matrice);
	mat4	invert(const mat4 matrice);
}

#pragma once

struct mat3;
#include "mat3.hpp"
struct vec4;
#include "vec4.hpp"

namespace matrix {
	struct mat4 {
		float	data[16];

		mat4(void);
		mat4(const mat4& rhs);
		mat4(const mat3& rhs);
		mat4&	operator=(const mat4& rhs);

		mat4	operator+(const mat4& rhs) const;
		mat4&	operator+=(const mat4& rhs);
		mat4	operator-(const mat4& rhs) const;
		mat4&	operator-=(const mat4& rhs);
		mat4	operator*(const mat4& rhs) const;
		mat4&	operator*=(const mat4& rhs);
		vec4	operator*(const vec4& rhs) const;
		mat4	operator/(const mat4& rhs) const;
		mat4&	operator/=(const mat4& rhs);

		bool	operator==(const mat4& rhs) const;
		bool	operator!=(const mat4& rhs) const;
	};

	void	identity(mat4& matrice);
	float	determinant(const mat4& matrice);
	mat4	invert(const mat4& matrice);
}

#pragma once

namespace matrix { struct mat3; }
#include "mat3.hpp"
namespace matrix { struct vec3; }
#include "vec3.hpp"
namespace matrix { struct vec4; }
#include "vec4.hpp"

#include <ostream>

namespace matrix {
	struct mat4 {
		float	data[16];

		mat4(void);
		mat4(const mat4& rhs);
		mat4(const mat3& rhs);
		mat4&	operator=(const mat4& rhs);

		mat4		operator+(const mat4& rhs) const;
		mat4&		operator+=(const mat4& rhs);
		mat4		operator-(const mat4& rhs) const;
		mat4&		operator-=(const mat4& rhs);
		mat4		operator-(void) const;
		mat4		operator*(const mat4& rhs) const;
		mat4&		operator*=(const mat4& rhs);
		vec3		operator*(const vec3& rhs) const;
		vec4		operator*(const vec4& rhs) const;
		mat4		operator*(const float scalar) const;
		mat4&		operator*=(const float scalar);
		friend mat4	operator*(const float scalar, const mat4& rhs);
		mat4		operator/(const mat4& rhs) const;
		mat4&		operator/=(const mat4& rhs);

		bool	operator==(const mat4& rhs) const;
		bool	operator!=(const mat4& rhs) const;

		void	transpose(void);
		void	scale(const vec3& vector);
	};
	std::ostream&	operator<<(std::ostream& os, const mat4& matrice);
	mat4			operator*(const float scalar, const mat4& rhs);

	void	identity(mat4& matrice);
	float	determinant(const mat4& matrice);
	mat4	invert(const mat4& matrice);
	mat4	transpose(const mat4& matrice);
	mat4	scale(const mat4& matrice, const vec3& vector);
}

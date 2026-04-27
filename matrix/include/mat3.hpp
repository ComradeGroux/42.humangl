#pragma once

namespace matrix { struct vec3; }
#include "vec3.hpp"
namespace matrix { struct mat4; }
#include "mat4.hpp"

#include <ostream>

namespace matrix {
	struct mat3 {
		float	data[9];
		
		mat3(void);
		mat3(const mat3& rhs);
		mat3(const mat4& rhs);
		mat3&	operator=(const mat3& rhs);
		
		mat3		operator+(const mat3& rhs) const;
		mat3&		operator+=(const mat3& rhs);
		mat3		operator-(const mat3& rhs) const;
		mat3&		operator-=(const mat3& rhs);
		mat3		operator-(void) const;
		mat3		operator*(const mat3& rhs) const;
		mat3&		operator*=(const mat3& rhs);
		vec3		operator*(const vec3& rhs) const;
		mat3		operator*(const float scalar) const;
		mat3&		operator*=(const float scalar);
		friend mat3	operator*(const float scalar, const mat3& rhs);
		mat3		operator/(const mat3& rhs) const;
		mat3&		operator/=(const mat3& rhs);

		bool	operator==(const mat3& rhs) const;
		bool	operator!=(const mat3& rhs) const;

		float&			operator[](int i);
		const float&	operator[](int i) const;
		const float*	ptr(void) const;

		void	transpose(void);
		void	normalize(void);
	};
	std::ostream&	operator<<(std::ostream& os, const mat3& matrice);

	void	identity(mat3& matrice);
	float	determinant(const mat3& matrice);
	mat3	normalize(const mat3& matrice);
	mat3	invert(const mat3& matrice);
	mat3	transpose(const mat3& matrice);
}

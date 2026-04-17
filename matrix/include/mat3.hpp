#pragma once

struct mat4;
#include "mat4.hpp"

namespace matrix {
	struct mat3 {
		float	data[9];
		
		mat3(void);
		mat3(const mat3& rhs);
		mat3(const mat4& rhs);
		mat3&	operator=(const mat3& rhs);
		
		mat3	operator+(const mat3& rhs) const;
		mat3&	operator+=(const mat3& rhs);
		mat3	operator-(const mat3& rhs) const;
		mat3&	operator-=(const mat3& rhs);
		mat3	operator-(void) const;
		mat3	operator*(const mat3& rhs) const;
		mat3&	operator*=(const mat3& rhs);
		mat3	operator*(const float scalar) const;
		mat3&	operator*=(const float scalar);
		mat3	operator/(const mat3& rhs) const;
		mat3&	operator/=(const mat3& rhs);

		bool	operator==(const mat3& rhs) const;
		bool	operator!=(const mat3& rhs) const;

		void	transpose(void);
	};

	void	identity(mat3& matrice);
	float	determinant(const mat3& matrice);
	mat3	invert(const mat3& matrice);
	mat3	transpose(const mat3& matrice);
}

#pragma once

namespace matrix { struct vec2; }
#include "vec2.hpp"

#include <ostream>

namespace matrix {
	struct mat2 {
		float	data[4];

		mat2(void);
		mat2(const mat2& rhs);
		mat2&	operator=(const mat2& rhs);

		mat2		operator+(const mat2& rhs) const;
		mat2&		operator+=(const mat2& rhs);
		mat2		operator-(const mat2& rhs) const;
		mat2&		operator-=(const mat2& rhs);
		mat2		operator-(void) const;
		mat2		operator*(const mat2& rhs) const;
		mat2&		operator*=(const mat2& rhs);
		vec2		operator*(const vec2& rhs) const;
		mat2		operator*(const float scalar) const;
		mat2&		operator*=(const float scalar);
		friend mat2	operator*(const float scalar, const mat2& rhs);
		mat2		operator/(const mat2& rhs) const;
		mat2&		operator/=(const mat2& rhs);

		bool	operator==(const mat2& rhs) const;
		bool	operator!=(const mat2& rhs) const;

		float&			operator[](int i);
		const float&	operator[](int i) const;
		const float*	ptr(void) const;

		void	transpose(void);
	};
	std::ostream&	operator<<(std::ostream& os, const mat2& matrice);
	mat2			operator*(const float scalar, const mat2& rhs);

	void	identity(mat2& matrice);
	float	determinant(const mat2& matrice);
	mat2	invert(const mat2& matrice);
	mat2	transpose(const mat2& matrice);
}

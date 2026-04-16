#pragma once

namespace matrix {
	struct mat3 {
		float	data[9];
		
		mat3(void);
		mat3(const mat3& rhs);
		mat3&	operator=(const mat3& rhs);
		
		mat3	operator+(const mat3& rhs) const;
		mat3	operator-(const mat3& rhs) const;
		mat3	operator*(const mat3& rhs) const;
		mat3	operator/(const mat3& rhs) const;
	};

	void	identity(mat3& matrice);
	float	determinant(const mat3 matrice);
	mat3	invert(const mat3 matrice);
}

#pragma once

namespace matrix { struct mat3; }
#include "mat3.hpp"
namespace matrix { struct vec4; }
#include "vec4.hpp"

#include <ostream>

namespace matrix {
	struct vec3 {
		float	x;
		float	y;
		float	z;

		vec3(void);
		vec3(float data);
		vec3(float x, float y, float z);
		vec3(const vec3& rhs);
		vec3(const vec4& rhs);
		vec3&	operator=(const vec3& rhs);

		vec3		operator+(const vec3& rhs) const;
		vec3&		operator+=(const vec3& rhs);
		vec3		operator-(const vec3& rhs) const;
		vec3&		operator-=(const vec3& rhs);
		vec3		operator-(void) const;
		vec3		operator*(const vec3& rhs) const;
		vec3&		operator*=(const vec3& rhs);
		vec3		operator*(const mat3& rhs) const;
		vec3&		operator*=(const mat3& rhs);
		vec3		operator*(const float scalar) const;
		vec3&		operator*=(const float scalar);
		friend vec3	operator*(const float scalar, const vec3& rhs);
		vec3		operator/(const vec3& rhs) const;
		vec3&		operator/=(const vec3& rhs);
		vec3		operator/(const float scalar) const;
		vec3&		operator/=(const float scalar);

		bool	operator==(const vec3& rhs) const;
		bool	operator!=(const vec3& rhs) const;

		void	scale(float scalar);
		float	length(void) const;
		void	normalize(void);
	};
	std::ostream&	operator<<(std::ostream& os, const vec3& vector);
	vec3			operator*(const float scalar, const vec3& rhs);

	vec3	scale(const vec3& vector, float scalar);
	vec3	normalize(const vec3& vector);
	float	dot(const vec3& lhs, const vec3& rhs);
	vec3	cross(const vec3& lhs, const vec3& rhs);
}

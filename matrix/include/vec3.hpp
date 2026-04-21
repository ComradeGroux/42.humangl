#pragma once

namespace matrix { struct mat3; }
#include "mat3.hpp"
namespace matrix { struct vec2; }
#include "vec2.hpp"
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
		void	clamp(float min, float max);

		vec2	xy(void) const;
	};
	std::ostream&	operator<<(std::ostream& os, const vec3& vector);
	vec3			operator*(const float scalar, const vec3& rhs);

	vec3	fromHomogeneous(const vec4& vector);

	vec3	scale(const vec3& vector, float scalar);
	float	length(const vec3& vector);
	vec3	normalize(const vec3& vector);
	vec3	clamp(const vec3& vector, float min, float max);

	float	dot(const vec3& lhs, const vec3& rhs);
	vec3	cross(const vec3& lhs, const vec3& rhs);
	vec3	reflect(const vec3& vector, const vec3& normal);
	vec3	lerp(const vec3& a, const vec3& b, float t);
}

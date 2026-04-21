#pragma once

namespace matrix { struct vec2; }
#include "vec2.hpp"
namespace matrix { struct vec3; }
#include "vec3.hpp"
namespace matrix { struct mat4; }
#include "mat4.hpp"

#include <ostream>

namespace matrix {
	struct vec4 {
		float	x;
		float	y;
		float	z;
		float	w;

		vec4(void);
		vec4(float data);
		vec4(float x, float y, float z, float w);
		vec4(const vec3& rhs, float w);
		vec4(const vec4& rhs);
		vec4&	operator=(const vec4& rhs);

		vec4		operator+(const vec4& rhs) const;
		vec4&		operator+=(const vec4& rhs);
		vec4		operator-(const vec4& rhs) const;
		vec4&		operator-=(const vec4& rhs);
		vec4		operator-(void) const;
		vec4		operator*(const vec4& rhs) const;
		vec4&		operator*=(const vec4& rhs);
		vec4		operator*(const mat4& rhs) const;
		vec4&		operator*=(const mat4& rhs);
		vec4		operator*(const float scalar) const;
		vec4&		operator*=(const float scalar);
		friend vec4	operator*(const float scalar, const vec4& rhs);
		vec4		operator/(const vec4& rhs) const;
		vec4&		operator/=(const vec4& rhs);
		vec4		operator/(const float scalar) const;
		vec4&		operator/=(const float scalar);

		bool	operator==(const vec4& rhs) const;
		bool	operator!=(const vec4& rhs) const;

		void	scale(float scalar);
		float	length(void) const;
		void	normalize(void);
		void	clamp(float min, float max);

		vec3	xyz(void) const;
		vec2	xy(void) const;
	};
	std::ostream&	operator<<(std::ostream& os, const vec4& vector);
	vec4			operator*(const float scalar, const vec4& rhs);

	vec4	scale(const vec4& vector, float scalar);
	float	length(const vec4& vector);
	vec4	normalize(const vec4& vector);
	vec4	clamp(const vec4& vector, float min, float max);

	float	dot(const vec4& lhs, const vec4& rhs);
	vec3	cross(const vec4& lhs, const vec4& rhs);
	vec4	reflect(const vec4& vector, const vec4& normal);
	vec4	lerp(const vec4& a, const vec4& b, float t);
}

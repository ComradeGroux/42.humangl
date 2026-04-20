#pragma once

namespace matrix { struct vec3; }
#include "vec3.hpp"
namespace matrix { struct vec4; }
#include "vec4.hpp"

#include <ostream>

namespace matrix {
	struct vec2 {
		float	x;
		float	y;
		
		vec2(void);
		vec2(float data);
		vec2(float x, float y);
		vec2(const vec2& rhs);
		vec2(const vec3& rhs);
		vec2(const vec4& rhs);
		vec2&	operator=(const vec2& rhs);

		vec2		operator+(const vec2& rhs) const;
		vec2&		operator+=(const vec2& rhs);
		vec2		operator-(const vec2& rhs) const;
		vec2&		operator-=(const vec2& rhs);
		vec2		operator-(void) const;
		vec2		operator*(const vec2& rhs) const;
		vec2&		operator*=(const vec2& rhs);
		vec2		operator*(const float scalar) const;
		vec2&		operator*=(const float scalar);
		friend vec2	operator*(const float scalar, const vec2& rhs);
		vec2		operator/(const vec2& rhs) const;
		vec2&		operator/=(const vec2& rhs);
		vec2		operator/(const float scalar) const;
		vec2&		operator/=(const float scalar);

		bool	operator==(const vec2& rhs) const;
		bool	operator!=(const vec2& rhs) const;

		void	scale(float scalar);
		float	length(void) const;
		void	normalize(void);
	};
	std::ostream&	operator<<(std::ostream& os, const vec2& vector);
	vec2			operator*(const float scalar, const vec2& rhs);

	vec2	scale(const vec2& vector, float scalar);
	float	length(const vec2& vector);
	vec2	normalize(const vec2& vector);
}

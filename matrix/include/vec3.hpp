#pragma once

namespace matrix {
	struct vec3 {
		float	x;
		float	y;
		float	z;

		vec3(void);
		vec3(float data);
		vec3(float x, float y, float z);
		vec3(const vec3& rhs);
		vec3&	operator=(const vec3& rhs);

		vec3	operator+(const vec3& rhs) const;
		vec3	operator-(const vec3& rhs) const;
		vec3	operator*(const vec3& rhs) const;
		vec3	operator*(const float scalar) const;
		vec3	operator/(const vec3& rhs) const;
		vec3	operator/(const float scalar) const;

		void	scale(float scalar);
		float	length(void) const;
		void	normalize(void);
	};

	vec3	scale(const vec3 vector, float scalar);
	vec3	normalize(const vec3 vector);
	float	dot(const vec3 lhs, const vec3 rhs);
	vec3	cross(const vec3 lhs, const vec3 rhs);
}
#pragma once

namespace matrix {
	struct vec3;
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
	struct vec4;
	struct mat4 {
		float	data[16];

		mat4(void);
		mat4(const mat4& rhs);
		mat4&	operator=(const mat4& rhs);

		mat4	operator+(const mat4& rhs) const;
		mat4	operator-(const mat4& rhs) const;
		mat4	operator*(const mat4& rhs) const;
		vec4	operator*(const vec4& rhs) const;
		mat4	operator/(const mat4& rhs) const;
	};

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
	struct vec4 {
		float	x;
		float	y;
		float	z;
		float	w;

		vec4(void);
		vec4(float data);
		vec4(float x, float y, float z, float w);
		vec4(const vec4& rhs);
		vec4&	operator=(const vec4& rhs);

		vec4	operator+(const vec4& rhs) const;
		vec4	operator-(const vec4& rhs) const;
		vec4	operator*(const vec4& rhs) const;
		vec4	operator*(const float scalar) const;
		vec4	operator/(const vec4& rhs) const;
		vec4	operator/(const float scalar) const;

		void	scale(float scalar);
		float	length(void) const;
		void	normalize(void);
	};

	vec3	scale(const vec3 vector, float scalar);
	vec4	scale(const vec4 vector, float scalar);
	vec3	normalize(const vec3 vector);
	vec4	normalize(const vec4 vector);
	float	dot(const vec3 lhs, const vec3 rhs);
	float	dot(const vec4 lhs, const vec4 rhs);
	vec3	cross(const vec3 lhs, const vec3 rhs);
	vec3	cross(const vec4 lhs, const vec4 rhs);

	void	identity(mat3& matrice);
	void	identity(mat4& matrice);
	float	determinant(const mat3 matrice);
	float	determinant(const mat4 matrice);
	mat3	invert(const mat3 matrice);
	mat4	invert(const mat4 matrice);

	float	deg_to_radians(float degrees);
	float	rad_to_degrees(float radians);
};

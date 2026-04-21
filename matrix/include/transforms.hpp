#pragma once

#include "vec3.hpp"
#include "mat3.hpp"
#include "mat4.hpp"

namespace matrix {
	mat3	normalMatrix(const mat4& model);
	mat4	translate(const mat4& matrice, const vec3& vector);
	mat4	rotate(const mat4& matrice, float angle_degrees, const vec3& axis);
	mat4	rotateX(const mat4& matrice, float angle_degrees);
	mat4	rotateY(const mat4& matrice, float angle_degrees);
	mat4	rotateZ(const mat4& matrice, float angle_degrees);
	mat4	lookAt(const vec3& eye, const vec3& center, const vec3& up);
	mat4	perspective(float fov_degree, float aspect, float near, float far);
	mat4	ortho(float left, float right, float bottom, float top, float near, float far);
}

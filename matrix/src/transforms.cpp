#include "transforms.hpp"

matrix::mat3	matrix::normalMatrix(const mat4& model)
{
	return transpose(invert(mat3(model)));
}

matrix::mat4	matrix::translate(const mat4& matrice, const vec3& vector)
{
	(void)vector;
	return matrice;
}

matrix::mat4	matrix::rotate(const mat4& matrice, float angle_radians, const vec3& axis)
{
	(void)angle_radians;
	(void)axis;
	return matrice;
}

matrix::mat4	matrix::lookAt(const vec3& eye, const vec3& center, const vec3& up)
{
	(void)eye;
	(void)center;
	(void)up;
	return mat4();
}

matrix::mat4	matrix::perspective(float fov, float aspect, float near, float far)
{
	(void)fov;
	(void)aspect;
	(void)near;
	(void)far;
	return mat4();
}

matrix::mat4	matrix::ortho(float left, float right, float bottom, float top, float near, float far)
{
	(void)left;
	(void)right;
	(void)bottom;
	(void)top;
	(void)near;
	(void)far;
	return mat4();
}

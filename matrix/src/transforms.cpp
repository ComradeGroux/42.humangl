#include "transforms.hpp"
#include "utils.hpp"

#include <cmath>

matrix::mat3	matrix::normalMatrix(const mat4& model)
{
	return transpose(invert(mat3(model)));
}

matrix::mat4	matrix::translate(const mat4& matrice, const vec3& vector)
{
	mat4	translation;
	identity(translation);

	translation.data[12] = vector.x;
	translation.data[13] = vector.y;
	translation.data[14] = vector.z;

	return matrice * translation;
}

matrix::mat4	matrix::rotate(const mat4& matrice, float angle_degrees, const vec3& axis)
{
	vec3	a = normalize(axis);
	float	angle = deg_to_radians(angle_degrees);
	float	cos = std::cos(angle);
	float	sin = std::sin(angle);
	float	tan = 1.0f - cos;
	mat4	rotation;

	rotation.data[0]  = tan * a.x * a.x + cos;
	rotation.data[1]  = tan * a.x * a.y + sin * a.z;
	rotation.data[2]  = tan * a.x * a.z - sin * a.y;
	rotation.data[3]  = 0.0f;

	rotation.data[4]  = tan * a.x * a.y - sin * a.z;
	rotation.data[5]  = tan * a.y * a.y + cos;
	rotation.data[6]  = tan * a.y * a.z + sin * a.x;
	rotation.data[7]  = 0.0f;

	rotation.data[8]  = tan * a.x * a.z + sin * a.y;
	rotation.data[9]  = tan * a.y * a.z - sin * a.x;
	rotation.data[10] = tan * a.z * a.z + cos;
	rotation.data[11] = 0.0f;

	rotation.data[12] = 0.0f;
	rotation.data[13] = 0.0f;
	rotation.data[14] = 0.0f;
	rotation.data[15] = 1.0f;

	return matrice * rotation;
}

matrix::mat4	matrix::rotateX(const matrix::mat4& matrice, float angle_degrees)
{
	mat4	rotation;
	identity(rotation);
	float	angle = deg_to_radians(angle_degrees);
	float	cos = std::cos(angle);
	float	sin = std::sin(angle);

	rotation.data[5] = cos;
	rotation.data[6] = sin;
	rotation.data[9] = -sin;
	rotation.data[10] = cos;

	return matrice * rotation;
}

matrix::mat4	matrix::rotateY(const matrix::mat4& matrice, float angle_degrees)
{
	mat4	rotation;
	identity(rotation);
	float	angle = deg_to_radians(angle_degrees);
	float	cos = std::cos(angle);
	float	sin = std::sin(angle);

	rotation.data[0] = cos;
	rotation.data[2] = -sin;
	rotation.data[8] = sin;
	rotation.data[10] = cos;

	return matrice * rotation;
}

matrix::mat4	matrix::rotateZ(const matrix::mat4& matrice, float angle_degrees)
{
	mat4	rotation;
	identity(rotation);
	float	angle = deg_to_radians(angle_degrees);
	float	cos = std::cos(angle);
	float	sin = std::sin(angle);

	rotation.data[0] = cos;
	rotation.data[1] = sin;
	rotation.data[4] = -sin;
	rotation.data[5] = cos;

	return matrice * rotation;
}

matrix::mat4	matrix::lookAt(const vec3& eye, const vec3& center, const vec3& up)
{
	mat4	lookDirection;
	identity(lookDirection);

	vec3	forward = center - eye;
	forward.normalize();

	vec3	right = cross(forward, up);
	right.normalize();

	vec3	realUp = cross(right, forward);
	realUp.normalize();

	lookDirection.data[0]  =  right.x;
	lookDirection.data[1]  =  right.y;
	lookDirection.data[2]  =  right.z;
	lookDirection.data[3]  = -dot(right, eye);

	lookDirection.data[4]  =  realUp.x;
	lookDirection.data[5]  =  realUp.y;
	lookDirection.data[6]  =  realUp.z;
	lookDirection.data[7]  = -dot(realUp, eye);

	lookDirection.data[8]  = -forward.x;
	lookDirection.data[9]  = -forward.y;
	lookDirection.data[10] = -forward.z;
	lookDirection.data[11] =  dot(forward, eye);

	lookDirection.transpose();

	return lookDirection;
}

matrix::mat4	matrix::perspective(float fov, float aspect, float near, float far)
{
	mat4	pers;
	float	tanHalfFov = std::tan(fov / 2.0f);

	pers.data[0]  = 1.0f / (aspect * tanHalfFov);
	pers.data[5]  = 1.0f  / tanHalfFov;
	pers.data[10] = -(far + near) / (far - near);
	pers.data[11] = -1.0f;
	pers.data[14] = -(2.0f * far * near) / (far - near);

	return pers;
}

matrix::mat4	matrix::ortho(float left, float right, float bottom, float top, float near, float far)
{
	mat4	orth;
	identity(orth);

	orth.data[0]  = 2.0f / (right - left);
	orth.data[5]  = 2.0f / (top - bottom);
	orth.data[10] = -2.0f / (far - near);

	orth.data[12] = -(right + left) / (right - left);
	orth.data[13] = -(top + bottom) / (top - bottom);
	orth.data[14] = -(far + near) / (far - near);

	return orth;
}

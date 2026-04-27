#include "lerp.hpp"

#include <cmath>

matrix::vec2	matrix::lerp(const vec2& a, const vec2& b, float t)
{
	vec2	res;

	res.x = a.x + t * (b.x - a.x);
	res.y = a.y + t * (b.y - a.y);

	return res;
}

matrix::vec3	matrix::lerp(const vec3&a, const vec3& b, float t)
{
	vec3	res;

	res.x = a.x + t * (b.x - a.x);
	res.y = a.y + t * (b.y - a.y);
	res.z = a.z + t * (b.z - a.z);

	return res;
}

matrix::vec4	matrix::lerp(const vec4&a, const vec4& b, float t)
{
	vec4	res;

	res.x = a.x + t * (b.x - a.x);
	res.y = a.y + t * (b.y - a.y);
	res.z = a.z + t * (b.z - a.z);
	res.w = a.w + t * (b.w - a.w);

	return res;
}

matrix::mat2		matrix::lerp(const mat2& a, const mat2& b, float t)
{
	mat2	res;

	for (unsigned char i = 0; i < 4; i++)
		res.data[i] = a.data[i] + t * (b.data[i] - a.data[i]);

	return res;
}

matrix::mat3		matrix::lerp(const mat3& a, const mat3& b, float t)
{
	mat3	res;

	for (unsigned char i = 0; i < 9; i++)
		res.data[i] = a.data[i] + t * (b.data[i] - a.data[i]);

	return res;
}

matrix::mat4		matrix::lerp(const mat4& a, const mat4& b, float t)
{
	mat4	res;

	for (unsigned char i = 0; i < 16; i++)
		res.data[i] = a.data[i] + t * (b.data[i] - a.data[i]);

	return res;
}

matrix::quaternion	matrix::lerp(const quaternion& a, const quaternion& b, float t)
{
	quaternion	res;

	res.h = a.h + t * (b.h - a.h);
	res.i = a.i + t * (b.i - a.i);
	res.j = a.j + t * (b.j - a.j);
	res.k = a.k + t * (b.k - a.k);

	return res;
}

matrix::vec2		matrix::slerp(const vec2& a, const vec2& b, float t)
{
	vec2	tmpB = b;
	float	d = dot(a, tmpB);
	if (d < 0.0f)
	{
		tmpB = -tmpB;
		d = -d;
	}

	float	q = std::acos(d);

	vec2	tmpLHS = ((std::sin((1 - t) * q)) / std::sin(q)) * a;
	vec2	tmpRHS = (std::sin(t * q) / std::sin(q)) * tmpB;

	return tmpLHS + tmpRHS;
}

matrix::vec3		matrix::slerp(const vec3& a, const vec3& b, float t)
{
	vec3	tmpB = b;
	float	d = dot(a, tmpB);
	if (d < 0.0f)
	{
		tmpB = -tmpB;
		d = -d;
	}

	float	q = std::acos(d);

	vec3	tmpLHS = ((std::sin((1 - t) * q)) / std::sin(q)) * a;
	vec3	tmpRHS = (std::sin(t * q) / std::sin(q)) * tmpB;

	return tmpLHS + tmpRHS;
}

matrix::vec4		matrix::slerp(const vec4& a, const vec4& b, float t)
{
	vec4	tmpB = b;
	float	d = dot(a, tmpB);
	if (d < 0.0f)
	{
		tmpB = -tmpB;
		d = -d;
	}

	float	q = std::acos(d);

	vec4	tmpLHS = ((std::sin((1 - t) * q)) / std::sin(q)) * a;
	vec4	tmpRHS = (std::sin(t * q) / std::sin(q)) * tmpB;

	return tmpLHS + tmpRHS;
}

matrix::mat2		matrix::slerp(const mat2& a, const mat2& b, float t)
{
	return lerp(a, b, t);
}

matrix::mat3		matrix::slerp(const mat3& a, const mat3& b, float t)
{
	return mat3(slerp(mat4(a), mat4(b), t));
}

matrix::mat4		matrix::slerp(const mat4& a, const mat4& b, float t)
{
	return slerp(a.toQuat(), b.toQuat(), t).toMat4();
}

matrix::quaternion	matrix::slerp(const quaternion& a, const quaternion& b, float t)
{
	quaternion	tmp = b;
	float	d = dot(a, tmp);
	if (d < 0.0f)
	{
		d = -d;
		tmp = -tmp;
	}
	d = std::acos(d);

	return (std::sin((1 - t) * d) / std::sin(d) * a) + (std::sin(t * d) / std::sin(d)) * b;
}

matrix::vec2		matrix::nlerp(const vec2& a, const vec2& b, float t)
{
	vec2	res = lerp(a, b, t);
	res.normalize();

	return res;
}

matrix::vec3		matrix::nlerp(const vec3& a, const vec3& b, float t)
{
	vec3	res = lerp(a, b, t);
	res.normalize();

	return res;
}

matrix::vec4		matrix::nlerp(const vec4& a, const vec4& b, float t)
{
	vec4	res = lerp(a, b, t);
	res.normalize();

	return res;
}

matrix::mat2		matrix::nlerp(const mat2& a, const mat2& b, float t)
{
	mat2	res = lerp(a, b, t);
	res.normalize();

	return res;
}

matrix::mat3		matrix::nlerp(const mat3& a, const mat3& b, float t)
{
	mat3	res = lerp(a, b, t);
	res.normalize();

	return res;
}

matrix::mat4		matrix::nlerp(const mat4& a, const mat4& b, float t)
{
	mat4	res = lerp(a, b, t);
	res.normalize();

	return res;
}

matrix::quaternion	matrix::nlerp(const quaternion& a, const quaternion& b, float t)
{
	quaternion	res = lerp(a, b, t);
	res.normalize();

	return res;
}


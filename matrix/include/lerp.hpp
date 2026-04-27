#pragma once

#include "vec2.hpp"
#include "vec3.hpp"
#include "vec4.hpp"
#include "mat2.hpp"
#include "mat3.hpp"
#include "mat4.hpp"
#include "quaternion.hpp"

namespace matrix {
	vec2		lerp(const vec2& a, const vec2& b, float t);
	vec3		lerp(const vec3& a, const vec3& b, float t);
	vec4		lerp(const vec4& a, const vec4& b, float t);
	mat2		lerp(const mat2& a, const mat2& b, float t);
	mat3		lerp(const mat3& a, const mat3& b, float t);
	mat4		lerp(const mat4& a, const mat4& b, float t);
	quaternion	lerp(const quaternion& a, const quaternion& b, float t);

	vec2		slerp(const vec2& a, const vec2& b, float t);
	vec3		slerp(const vec3& a, const vec3& b, float t);
	vec4		slerp(const vec4& a, const vec4& b, float t);
	mat2		slerp(const mat2& a, const mat2& b, float t);
	mat3		slerp(const mat3& a, const mat3& b, float t);
	mat4		slerp(const mat4& a, const mat4& b, float t);
	quaternion	slerp(const quaternion& a, const quaternion& b, float t);

	vec2		nlerp(const vec2& a, const vec2& b, float t);
	vec3		nlerp(const vec3& a, const vec3& b, float t);
	vec4		nlerp(const vec4& a, const vec4& b, float t);
	mat2		nlerp(const mat2& a, const mat2& b, float t);
	mat3		nlerp(const mat3& a, const mat3& b, float t);
	mat4		nlerp(const mat4& a, const mat4& b, float t);
	quaternion	nlerp(const quaternion& a, const quaternion& b, float t);
}
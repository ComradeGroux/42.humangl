#pragma once

namespace matrix {
	inline float	deg_to_radians(float degrees) {
		return degrees * 3.14159265358979323846f / 180.0f;
	};
	inline float	rad_to_degrees(float radians) {
		return radians * 180.0f / 3.14159265358979323846f;
	};

	float			clamp(float value, float min, float max);
	float			smoothstep(float edge0, float edge1, float t);
}

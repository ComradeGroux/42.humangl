#pragma once

namespace matrix {
	inline float	deg_to_radians(float degrees);
	inline float	rad_to_degrees(float radians);
	float			clamp(float value, float min, float max);
	float			smoothstep(float edge0, float edge1, float t);
}

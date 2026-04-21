#pragma once

namespace matrix {
	float	deg_to_radians(float degrees);
	float	rad_to_degrees(float radians);
	float	clamp(float value, float min, float max);
	float	smoothstep(float edge0, float edge1, float t);
}

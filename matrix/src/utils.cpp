#include "matrix.hpp"

float matrix::deg_to_radians(float degrees)
{
	return degrees * 3.14159265358979323846f / 180.0f;
}

float matrix::rad_to_degrees(float radians)
{
	return radians * 180.0f / 3.14159265358979323846f;
}

float	matrix::clamp(float value, float min, float max)
{
	if (value < min)
		return min;
	else if (value > max)
		return max;
	return value;
}

float	matrix::smoothstep(float edge0, float edge1, float t)
{
	t = clamp((t - edge0) / (edge1 - edge0), 0, 1);

	return t * t * (3.0f - 2.0f * t);
}

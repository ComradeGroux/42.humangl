#include "matrix.hpp"

float matrix::deg_to_radians(float degrees)
{
	return degrees * 3.14159265358979323846f / 180.0f;
}

float matrix::rad_to_degrees(float radians)
{
	return radians * 180.0f / 3.14159265358979323846f;
}

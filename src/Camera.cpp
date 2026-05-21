#include "Camera.hpp"

#include <math.h>

Camera::Camera(matrix::vec3 position, float yaw, float pitch) : _pos(position), _yaw(yaw), _pitch(pitch)
{
	_updateVectors();
}

Camera::~Camera(void)
{
}

void	Camera::_updateVectors(void)
{
	matrix::vec3	front;

	front.x = std::cos(matrix::deg_to_radians(_yaw)) * std::cos(matrix::deg_to_radians(_pitch));
	front.y = std::sin(matrix::deg_to_radians(_pitch));
	front.z = std::sin(matrix::deg_to_radians(_yaw)) * std::cos(matrix::deg_to_radians(_pitch));

	_front = matrix::normalize(front);
	_right = matrix::normalize(matrix::cross(_front, matrix::vec3(0.0f, 1.0f, 0.0f)));
	_up = matrix::normalize(matrix::cross(_right, _front));
}

matrix::mat4	Camera::getProjectionMatrix(float aspectRatio) const
{
	return matrix::perspective(_fov, aspectRatio, 0.1f, 100.0f);
}

matrix::mat4	Camera::getViewMatrix(void) const
{
	return matrix::lookAt(_pos, _pos + _front, _up);
}

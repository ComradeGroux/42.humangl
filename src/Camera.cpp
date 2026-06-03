#include "Camera.hpp"

#include <math.h>

Camera::Camera(matrix::vec3 position, float yaw, float pitch) : _pos(position), _yaw(yaw), _pitch(pitch)
{
	_r = 0.0f;
	_theta = 0.0f;
	_pitch = 0.0f;
	_updateVectors();
}

Camera::Camera(float r, float theta, float phi)
{
	_pos = { 0.0f, 0.0f, 0.0f };
	_yaw = 0;
	_pitch = 0;

	_r = r;
	_theta = theta;
	_phi = phi;
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
	return matrix::perspective(_fov, aspectRatio, 0.001f, 100.0f);
}

matrix::mat4	Camera::getViewMatrix(void) const
{
	return matrix::lookAt(_pos, _pos + _front, _up);
}

matrix::mat4	Camera::getViewCenterMatrix(void) const
{
	return matrix::lookAt(_pos, {0.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f});
}

void	Camera::updateRotation(double deltaTime)
{
	_theta += deltaTime;

	_pos = {_r * std::cos(_phi) * std::cos(_theta),
			_r * std::sin(_phi),
			_r * std::cos(_phi) * std::sin(_theta)};
}

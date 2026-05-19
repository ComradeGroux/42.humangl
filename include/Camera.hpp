#pragma once

#include "matrix.hpp"

class Camera {
	private:
		matrix::vec3	_pos;
		matrix::vec3	_front;
		matrix::vec3	_up;
		matrix::vec3	_right;

		float	_yaw;
		float	_pitch;

		float	_fov = 80.0f;

		void	_updateVectors(void);

	public:
		Camera(matrix::vec3 position, float yaw, float pitch);
		~Camera(void);

		matrix::mat4	getProjectionMatrix(float aspectRatio) const;
		matrix::mat4	getViewMatrix(void) const;
};

#pragma once

#include "matrix.hpp"

#include <stack>

class MatrixStack {
	private:
		std::stack<matrix::mat4>	_stack;

	public:
		MatrixStack(void);

		void	push(void);
		void	pop(void);
		void	apply(matrix::mat4 transform);

		matrix::mat4&		top(void);
		const matrix::mat4&	top(void) const;

		void	translate(const matrix::vec3& vector);
		void	rotate(float angle_degrees, const matrix::vec3& axis);
		void	scale(const matrix::vec3& vector);
};

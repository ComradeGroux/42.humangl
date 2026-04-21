#include "MatrixStack.hpp"

MatrixStack::MatrixStack(void)
{
	matrix::mat4	init;
	matrix::identity(init);
	_stack.push(init);
}

void	MatrixStack::push(void)
{
	_stack.push(_stack.top());
}

void	MatrixStack::pop(void)
{
	_stack.pop();
}

void	MatrixStack::apply(matrix::mat4 transform)
{
	_stack.top() *= transform;
}

matrix::mat4&	MatrixStack::top(void)
{
	return _stack.top();
}

const matrix::mat4&	MatrixStack::top(void) const
{
	return _stack.top();
}

void	MatrixStack::translate(const matrix::vec3& vector)
{
	_stack.top() = matrix::translate(_stack.top(), vector);
}

void	MatrixStack::rotate(float angle_degrees, const matrix::vec3& axis)
{
	_stack.top() = matrix::rotate(_stack.top(), angle_degrees, axis);
}

void	MatrixStack::scale(const matrix::vec3& vector)
{
	_stack.top() = matrix::scale(_stack.top(), vector);
}

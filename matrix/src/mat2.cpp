#include "mat2.hpp"

matrix::mat2::mat2(void)
{
	for (unsigned char i = 0; i < 4; i++)
		this->data[i] = 0;
}

matrix::mat2::mat2(const mat2& rhs)
{
	for (unsigned char i = 0; i < 4; i++)
		this->data[i] = rhs.data[i];
}

matrix::mat2&	matrix::mat2::operator=(const mat2& rhs)
{
	for (unsigned char i = 0; i < 4; i++)
		this->data[i] = rhs.data[i];

	return *this;
}

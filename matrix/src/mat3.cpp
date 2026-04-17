#include "mat3.hpp"

#include <stdexcept>
#include <cmath>

matrix::mat3::mat3(void)
{
	for (unsigned char i = 0; i < 9; i++)
		data[i] = 0.0f;
}

matrix::mat3::mat3(const mat3& rhs)
{
	*this = rhs;
}

matrix::mat3::mat3(const mat4& rhs)
{
	this->data[0] = rhs.data[0];  this->data[3] = rhs.data[4];  this->data[6] = rhs.data[8];
	this->data[1] = rhs.data[1];  this->data[4] = rhs.data[5];  this->data[7] = rhs.data[9];
	this->data[2] = rhs.data[2];  this->data[5] = rhs.data[6];  this->data[8] = rhs.data[10];
}

matrix::mat3&	matrix::mat3::operator=(const mat3& rhs)
{
	for (unsigned char i = 0; i < 9; i++)
		data[i] = rhs.data[i];

	return *this;
}

matrix::mat3	matrix::mat3::operator+(const mat3& rhs) const
{
	mat3	res;

	res.data[0] = this->data[0] + rhs.data[0];	res.data[3] = this->data[3] + rhs.data[3];	res.data[6] = this->data[6] + rhs.data[6];
	res.data[1] = this->data[1] + rhs.data[1];	res.data[4] = this->data[4] + rhs.data[4];	res.data[7] = this->data[7] + rhs.data[7];
	res.data[2] = this->data[2] + rhs.data[2];	res.data[5] = this->data[5] + rhs.data[5];	res.data[8] = this->data[8] + rhs.data[8];

	return res;
}

matrix::mat3&	matrix::mat3::operator+=(const mat3& rhs)
{
	*this = *this + rhs;

	return *this;
}

matrix::mat3	matrix::mat3::operator-(const mat3& rhs) const
{
	mat3	res;

	res.data[0] = this->data[0] - rhs.data[0];	res.data[3] = this->data[3] - rhs.data[3];	res.data[6] = this->data[6] - rhs.data[6];
	res.data[1] = this->data[1] - rhs.data[1];	res.data[4] = this->data[4] - rhs.data[4];	res.data[7] = this->data[7] - rhs.data[7];
	res.data[2] = this->data[2] - rhs.data[2];	res.data[5] = this->data[5] - rhs.data[5];	res.data[8] = this->data[8] - rhs.data[8];

	return res;
}

matrix::mat3&	matrix::mat3::operator-=(const mat3& rhs)
{
	*this = *this - rhs;

	return *this;
}

matrix::mat3	matrix::mat3::operator*(const mat3& rhs) const
{
	mat3	res;

	res.data[0] = this->data[0] * rhs.data[0] + this->data[3] * rhs.data[1] + this->data[6] * rhs.data[2];
	res.data[1] = this->data[1] * rhs.data[0] + this->data[4] * rhs.data[1] + this->data[7] * rhs.data[2];
	res.data[2] = this->data[2] * rhs.data[0] + this->data[5] * rhs.data[1] + this->data[8] * rhs.data[2];

	res.data[3] = this->data[0] * rhs.data[3] + this->data[3] * rhs.data[4] + this->data[6] * rhs.data[5];
	res.data[4] = this->data[1] * rhs.data[3] + this->data[4] * rhs.data[4] + this->data[7] * rhs.data[5];
	res.data[5] = this->data[2] * rhs.data[3] + this->data[5] * rhs.data[4] + this->data[8] * rhs.data[5];

	res.data[6] = this->data[0] * rhs.data[6] + this->data[3] * rhs.data[7] + this->data[6] * rhs.data[8];
	res.data[7] = this->data[1] * rhs.data[6] + this->data[4] * rhs.data[7] + this->data[7] * rhs.data[8];
	res.data[8] = this->data[2] * rhs.data[6] + this->data[5] * rhs.data[7] + this->data[8] * rhs.data[8];

	return res;
}

matrix::mat3&	matrix::mat3::operator*=(const mat3& rhs)
{
	*this = *this * rhs;

	return *this;
}

matrix::mat3	matrix::mat3::operator/(const mat3& rhs) const
{
	return *this * invert(rhs);
}

matrix::mat3&	matrix::mat3::operator/=(const mat3& rhs)
{
	*this = *this / rhs;

	return *this;
}

bool	matrix::mat3::operator==(const mat3& rhs) const
{
	for (unsigned char i = 0; i < 9; i++)
	{
		if (this->data[i] != rhs.data[i])
			return false;
	}
	return true;
}

bool	matrix::mat3::operator!=(const mat3& rhs) const
{
	return !(*this == rhs);
}

void	matrix::identity(mat3& matrice)
{
	matrice.data[0] = 1.0f;	matrice.data[3] = 0.0f;	matrice.data[6] = 0.0f;
	matrice.data[1] = 0.0f;	matrice.data[4] = 1.0f;	matrice.data[7] = 0.0f;
	matrice.data[2] = 0.0f;	matrice.data[5] = 0.0f;	matrice.data[8] = 1.0f;
}

float	matrix::determinant(const mat3& matrice)
{
	float	det = 0.0f;

	det  = matrice.data[0] * (matrice.data[4] * matrice.data[8] - matrice.data[7] * matrice.data[5]);
	det -= matrice.data[3] * (matrice.data[1] * matrice.data[8] - matrice.data[7] * matrice.data[2]);
	det += matrice.data[6] * (matrice.data[1] * matrice.data[5] - matrice.data[4] * matrice.data[2]);

	return det;
}

matrix::mat3	matrix::invert(const mat3& matrice)
{
	float	det = determinant(matrice);
	if (std::fabs(det) < 1e-6f)
		#ifdef DEBUG
			throw std::runtime_error("Matrice is not invertible");
		#else
			return matrice;
		#endif

	float	inv = 1.0f / det;
	mat3	res;

	res.data[0] =  (matrice.data[4] * matrice.data[8] - matrice.data[5] * matrice.data[7]) * inv;
	res.data[1] = -(matrice.data[1] * matrice.data[8] - matrice.data[2] * matrice.data[7]) * inv;
	res.data[2] =  (matrice.data[1] * matrice.data[5] - matrice.data[2] * matrice.data[4]) * inv;

	res.data[3] = -(matrice.data[3] * matrice.data[8] - matrice.data[5] * matrice.data[6]) * inv;
	res.data[4] =  (matrice.data[0] * matrice.data[8] - matrice.data[2] * matrice.data[6]) * inv;
	res.data[5] = -(matrice.data[0] * matrice.data[5] - matrice.data[2] * matrice.data[3]) * inv;

	res.data[6] =  (matrice.data[3] * matrice.data[7] - matrice.data[4] * matrice.data[6]) * inv;
	res.data[7] = -(matrice.data[0] * matrice.data[7] - matrice.data[1] * matrice.data[6]) * inv;
	res.data[8] =  (matrice.data[0] * matrice.data[4] - matrice.data[1] * matrice.data[3]) * inv;

	return res;
}

#include "mat2.hpp"

#include <cmath>
#include <cassert>

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

matrix::mat2	matrix::mat2::operator+(const mat2& rhs) const
{
	mat2	res;

	res.data[0] = this->data[0] + rhs.data[0];	res.data[2] = this->data[2] + rhs.data[2];
	res.data[1] = this->data[1] + rhs.data[1];	res.data[3] = this->data[3] + rhs.data[3];

	return res;
}

matrix::mat2&	matrix::mat2::operator+=(const mat2& rhs)
{
	*this = *this + rhs;

	return *this;
}

matrix::mat2	matrix::mat2::operator-(const mat2& rhs) const
{
	mat2	res;

	res.data[0] = this->data[0] - rhs.data[0];	res.data[2] = this->data[2] - rhs.data[2];
	res.data[1] = this->data[1] - rhs.data[1];	res.data[3] = this->data[3] - rhs.data[3];

	return res;
}

matrix::mat2&	matrix::mat2::operator-=(const mat2& rhs)
{
	*this = *this - rhs;

	return *this;
}

matrix::mat2	matrix::mat2::operator-(void) const
{
	mat2	res;

	res.data[0] = -(this->data[0]);  res.data[2] = -(this->data[2]);
	res.data[1] = -(this->data[1]);  res.data[3] = -(this->data[3]);

	return res;
}

matrix::mat2	matrix::mat2::operator*(const mat2& rhs) const
{
	mat2	res;

	res.data[0] = this->data[0] * rhs.data[0] + this->data[2] * rhs.data[1];
	res.data[1] = this->data[1] * rhs.data[0] + this->data[3] * rhs.data[1];

	res.data[2] = this->data[0] * rhs.data[2] + this->data[2] * rhs.data[3];
	res.data[3] = this->data[1] * rhs.data[2] + this->data[3] * rhs.data[3];

	return res;
}

matrix::mat2&	matrix::mat2::operator*=(const mat2& rhs)
{
	*this = *this * rhs;

	return *this;
}

matrix::vec2	matrix::mat2::operator*(const vec2& rhs) const
{
	vec2 res;

	res.x = data[0] * rhs.x + data[2] * rhs.y;
	res.y = data[1] * rhs.x + data[3] * rhs.y;

	return res;
}

matrix::mat2	matrix::mat2::operator*(const float scalar) const
{
	mat2	res = *this;

	res.data[0] *= scalar;	res.data[2] *= scalar;
	res.data[1] *= scalar;	res.data[3] *= scalar;

	return res;
}

matrix::mat2&	matrix::mat2::operator*=(const float scalar)
{
	*this = *this * scalar;

	return *this;
}

matrix::mat2	matrix::operator*(const float scalar, const mat2& rhs)
{
	return rhs * scalar;
}

matrix::mat2	matrix::mat2::operator/(const mat2& rhs) const
{
	return *this * invert(rhs);
}

matrix::mat2&	matrix::mat2::operator/=(const mat2& rhs)
{
	*this = *this / rhs;

	return *this;
}

bool	matrix::mat2::operator==(const mat2& rhs) const
{
	for (unsigned char i = 0; i < 4; i++)
	{
		if (std::fabs(data[i] - rhs.data[i]) > 1e-6f)
			return false;
	}
	return true;
}

bool	matrix::mat2::operator!=(const mat2& rhs) const
{
	return !(*this == rhs);
}

float&	matrix::mat2::operator[](int i)
{
	#ifdef DEBUG
		assert(i >= 0 && i < 4);
	#endif
	return this->data[i];
}

const float&	matrix::mat2::operator[](int i) const
{
	#ifdef DEBUG
		assert(i >= 0 && i < 4);
	#endif
	return this->data[i];
}

const float*	matrix::mat2::ptr(void) const
{
	return &data[0];
}

void	matrix::mat2::transpose(void)
{
	mat2	tmp = *this;

	this->data[0] = tmp.data[0];  this->data[2] = tmp.data[1];
	this->data[1] = tmp.data[2];  this->data[3] = tmp.data[3];
}

std::ostream&	matrix::operator<<(std::ostream& os, const mat2& matrice)
{
	os << "/ " << matrice.data[0] << " " << matrice.data[2] << " \\" << std::endl;
	os << "\\ " << matrice.data[1] << " " << matrice.data[3] << " /" << std::endl;

	return os;
}

void	matrix::identity(mat2& matrice)
{
	matrice.data[0] = 1.0f;	matrice.data[2] = 0.0f;
	matrice.data[1] = 0.0f;	matrice.data[3] = 1.0f;
}

float	matrix::determinant(const mat2& matrice)
{
	return matrice.data[0] * matrice.data[3] - matrice.data[2] * matrice.data[1];
}

matrix::mat2	matrix::invert(const mat2& matrice)
{
	float	det = determinant(matrice);
	if (std::fabs(det) < 1e-6f)
		#ifdef DEBUG
			throw std::runtime_error("Matrice is not invertible");
		#else
			return matrice;
		#endif

	float	inv = 1.0f / det;
	mat2	res;

	res.data[0] =  matrice.data[3] * inv;  res.data[2] = -matrice.data[2] * inv;
	res.data[1] = -matrice.data[1] * inv;  res.data[3] =  matrice.data[0] * inv;

	return res;
}

matrix::mat2	matrix::transpose(const mat2& matrice)
{
	mat2	res = matrice;

	res.transpose();

	return res;
}

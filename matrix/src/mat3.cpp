#include "mat3.hpp"

#include <stdexcept>
#include <cmath>
#include <cassert>

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

matrix::mat3	matrix::mat3::operator-(void) const
{
	mat3	res;

	res.data[0] = -(this->data[0]);  res.data[3] = -(this->data[3]);  res.data[6] = -(this->data[6]);
	res.data[1] = -(this->data[1]);  res.data[4] = -(this->data[4]);  res.data[7] = -(this->data[7]);
	res.data[2] = -(this->data[2]);  res.data[5] = -(this->data[5]);  res.data[8] = -(this->data[8]);

	return res;
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

matrix::vec3	matrix::mat3::operator*(const vec3& rhs) const
{
	vec3 res;

	res.x = data[0] * rhs.x + data[3] * rhs.y + data[6] * rhs.z;
	res.y = data[1] * rhs.x + data[4] * rhs.y + data[7] * rhs.z;
	res.z = data[2] * rhs.x + data[5] * rhs.y + data[8] * rhs.z;

	return res;
}

matrix::mat3	matrix::mat3::operator*(const float scalar) const
{
	mat3	res = *this;

	res.data[0] *= scalar;	res.data[3] *= scalar;	res.data[6] *= scalar;
	res.data[1] *= scalar;	res.data[4] *= scalar;	res.data[7] *= scalar;
	res.data[2] *= scalar;	res.data[5] *= scalar;	res.data[8] *= scalar;

	return res;
}

matrix::mat3&	matrix::mat3::operator*=(const float scalar)
{
	*this = *this * scalar;

	return *this;
}

matrix::mat3	operator*(const float scalar, const matrix::mat3& rhs)
{
	return rhs * scalar;
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
		if (std::fabs(data[i] - rhs.data[i]) > 1e-6f)
			return false;
	}
	return true;
}

bool	matrix::mat3::operator!=(const mat3& rhs) const
{
	return !(*this == rhs);
}

float&	matrix::mat3::operator[](int i)
{
	#ifdef DEBUG
		assert(i >= 0 && i < 9);
	#endif
	return this->data[i];
}

const float&	matrix::mat3::operator[](int i) const
{
	#ifdef DEBUG
		assert(i >= 0 && i < 9);
	#endif
	return this->data[i];
}

const float*	matrix::mat3::ptr(void) const
{
	return &data[0];
}

void	matrix::mat3::transpose(void)
{
	mat3	tmp = *this;

	this->data[0] = tmp.data[0];  this->data[3] = tmp.data[1];  this->data[6] = tmp.data[2];
	this->data[1] = tmp.data[3];  this->data[4] = tmp.data[4];  this->data[7] = tmp.data[5];
	this->data[2] = tmp.data[6];  this->data[5] = tmp.data[7];  this->data[8] = tmp.data[8];
}

void	matrix::mat3::normalize(void)
{
	vec3	c0(this->data[0], this->data[1], this->data[2]);
	c0.normalize();

	vec3	c1(this->data[3], this->data[4], this->data[5]);
	float	dotLen = dot(c0, c1);
	c1 = c1 - dotLen * c0;
	c1.normalize();

	vec3	c2 = cross(c0, c1);
	this->data[0] = c0.x; this->data[3] = c1.x; this->data[6] = c2.x;
	this->data[1] = c0.y; this->data[4] = c1.y; this->data[7] = c2.y;
	this->data[2] = c0.z; this->data[5] = c1.z; this->data[8] = c2.z;
}

std::ostream&	matrix::operator<<(std::ostream& os, const mat3& matrice)
{
	os << "/ " << matrice.data[0] << " " << matrice.data[3] << " " << matrice.data[6] << " \\" << std::endl;
	os << "| " << matrice.data[1] << " " << matrice.data[4] << " " << matrice.data[7] << " |" << std::endl;
	os << "\\ " << matrice.data[2] << " " << matrice.data[5] << " " << matrice.data[8] << " /" << std::endl;

	return os;
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

matrix::mat3	matrix::normalize(const mat3& matrice)
{
	mat3	res = matrice;
	res.normalize();

	return res;
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

matrix::mat3	matrix::transpose(const mat3& matrice)
{
	mat3	res;

	res.data[0] = matrice.data[0];  res.data[3] = matrice.data[1];  res.data[6] = matrice.data[2];
	res.data[1] = matrice.data[3];  res.data[4] = matrice.data[4];  res.data[7] = matrice.data[5];
	res.data[2] = matrice.data[6];  res.data[5] = matrice.data[7];  res.data[8] = matrice.data[8];

	return res;
}

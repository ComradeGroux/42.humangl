#include "mat4.hpp"

#include <stdexcept>
#include <cmath>

matrix::mat4::mat4(void)
{
	for (unsigned char i = 0; i < 16; i++)
		data[i] = 0.0f;
}

matrix::mat4::mat4(const mat4& rhs)
{
	*this = rhs;
}

matrix::mat4::mat4(const mat3& rhs)
{
	this->data[0] = rhs.data[0];  this->data[4] = rhs.data[3];   this->data[8] = rhs.data[6];  this->data[12] = 0.0f;
	this->data[1] = rhs.data[1];  this->data[5] = rhs.data[4];   this->data[9] = rhs.data[7];  this->data[13] = 0.0f;
	this->data[2] = rhs.data[2];  this->data[6] = rhs.data[5];  this->data[10] = rhs.data[8];  this->data[14] = 0.0f;
	this->data[3] = 0.0f;		  this->data[7] = 0.0f;			this->data[11] = 0.0f;		   this->data[15] = 1.0f;
}

matrix::mat4&	matrix::mat4::operator=(const mat4& rhs)
{
	for (unsigned char i = 0; i < 16; i++)
		data[i] = rhs.data[i];

	return *this;
}

matrix::mat4	matrix::mat4::operator+(const mat4& rhs) const
{
	mat4	res;

	res.data[0] = this->data[0] + rhs.data[0];	res.data[4] = this->data[4] + rhs.data[4];	 res.data[8] =  this->data[8] + rhs.data[8];	res.data[12] = this->data[12] + rhs.data[12];
	res.data[1] = this->data[1] + rhs.data[1];	res.data[5] = this->data[5] + rhs.data[5];	 res.data[9] =  this->data[9] + rhs.data[9];	res.data[13] = this->data[13] + rhs.data[13];
	res.data[2] = this->data[2] + rhs.data[2];	res.data[6] = this->data[6] + rhs.data[6];	res.data[10] = this->data[10] + rhs.data[10];	res.data[14] = this->data[14] + rhs.data[14];
	res.data[3] = this->data[3] + rhs.data[3];	res.data[7] = this->data[7] + rhs.data[7];	res.data[11] = this->data[11] + rhs.data[11];	res.data[15] = this->data[15] + rhs.data[15];

	return res;
}

matrix::mat4&	matrix::mat4::operator+=(const mat4& rhs)
{
	*this = *this + rhs;

	return *this;
}

matrix::mat4	matrix::mat4::operator-(const mat4& rhs) const
{
	mat4	res;

	res.data[0] = this->data[0] - rhs.data[0];	res.data[4] = this->data[4] - rhs.data[4];	 res.data[8] =  this->data[8] - rhs.data[8];	res.data[12] = this->data[12] - rhs.data[12];
	res.data[1] = this->data[1] - rhs.data[1];	res.data[5] = this->data[5] - rhs.data[5];	 res.data[9] =  this->data[9] - rhs.data[9];	res.data[13] = this->data[13] - rhs.data[13];
	res.data[2] = this->data[2] - rhs.data[2];	res.data[6] = this->data[6] - rhs.data[6];	res.data[10] = this->data[10] - rhs.data[10];	res.data[14] = this->data[14] - rhs.data[14];
	res.data[3] = this->data[3] - rhs.data[3];	res.data[7] = this->data[7] - rhs.data[7];	res.data[11] = this->data[11] - rhs.data[11];	res.data[15] = this->data[15] - rhs.data[15];

	return res;
}

matrix::mat4&	matrix::mat4::operator-=(const mat4& rhs)
{
	*this = *this - rhs;

	return *this;
}

matrix::mat4	matrix::mat4::operator-(void) const
{
	mat4	res;

	res.data[0] = -(this->data[0]);	res.data[4] = -(this->data[4]);	 res.data[8] =  -(this->data[8]);	res.data[12] = -(this->data[12]);
	res.data[1] = -(this->data[1]);	res.data[5] = -(this->data[5]);	 res.data[9] =  -(this->data[9]);	res.data[13] = -(this->data[13]);
	res.data[2] = -(this->data[2]);	res.data[6] = -(this->data[6]);	res.data[10] = -(this->data[10]);	res.data[14] = -(this->data[14]);
	res.data[3] = -(this->data[3]);	res.data[7] = -(this->data[7]);	res.data[11] = -(this->data[11]);	res.data[15] = -(this->data[15]);

	return res;
}

matrix::mat4	matrix::mat4::operator*(const mat4& rhs) const
{
	mat4	res;

	res.data[0]  = this->data[0] * rhs.data[0] + this->data[4] * rhs.data[1] +  this->data[8] * rhs.data[2] + this->data[12] * rhs.data[3];
	res.data[1]  = this->data[1] * rhs.data[0] + this->data[5] * rhs.data[1] +  this->data[9] * rhs.data[2] + this->data[13] * rhs.data[3];
	res.data[2]  = this->data[2] * rhs.data[0] + this->data[6] * rhs.data[1] + this->data[10] * rhs.data[2] + this->data[14] * rhs.data[3];
	res.data[3]  = this->data[3] * rhs.data[0] + this->data[7] * rhs.data[1] + this->data[11] * rhs.data[2] + this->data[15] * rhs.data[3];

	res.data[4]  = this->data[0] * rhs.data[4] + this->data[4] * rhs.data[5] +  this->data[8] * rhs.data[6] + this->data[12] * rhs.data[7];
	res.data[5]  = this->data[1] * rhs.data[4] + this->data[5] * rhs.data[5] +  this->data[9] * rhs.data[6] + this->data[13] * rhs.data[7];
	res.data[6]  = this->data[2] * rhs.data[4] + this->data[6] * rhs.data[5] + this->data[10] * rhs.data[6] + this->data[14] * rhs.data[7];
	res.data[7]  = this->data[3] * rhs.data[4] + this->data[7] * rhs.data[5] + this->data[11] * rhs.data[6] + this->data[15] * rhs.data[7];

	res.data[8]  = this->data[0] * rhs.data[8] + this->data[4] * rhs.data[9] +  this->data[8] * rhs.data[10] + this->data[12] * rhs.data[11];
	res.data[9]  = this->data[1] * rhs.data[8] + this->data[5] * rhs.data[9] +  this->data[9] * rhs.data[10] + this->data[13] * rhs.data[11];
	res.data[10] = this->data[2] * rhs.data[8] + this->data[6] * rhs.data[9] + this->data[10] * rhs.data[10] + this->data[14] * rhs.data[11];
	res.data[11] = this->data[3] * rhs.data[8] + this->data[7] * rhs.data[9] + this->data[11] * rhs.data[10] + this->data[15] * rhs.data[11];

	res.data[12] = this->data[0] * rhs.data[12] + this->data[4] * rhs.data[13] +  this->data[8] * rhs.data[14] + this->data[12] * rhs.data[15];
	res.data[13] = this->data[1] * rhs.data[12] + this->data[5] * rhs.data[13] +  this->data[9] * rhs.data[14] + this->data[13] * rhs.data[15];
	res.data[14] = this->data[2] * rhs.data[12] + this->data[6] * rhs.data[13] + this->data[10] * rhs.data[14] + this->data[14] * rhs.data[15];
	res.data[15] = this->data[3] * rhs.data[12] + this->data[7] * rhs.data[13] + this->data[11] * rhs.data[14] + this->data[15] * rhs.data[15];

	return res;
}

matrix::mat4&	matrix::mat4::operator*=(const mat4& rhs)
{
	*this = *this * rhs;

	return *this;
}

matrix::vec3	matrix::mat4::operator*(const vec3& rhs) const
{
	return vec3(vec4(rhs, 1.0f) * *this);
}

matrix::vec4	matrix::mat4::operator*(const vec4& rhs) const
{
	return rhs * *this;
}

matrix::mat4	matrix::mat4::operator*(const float scalar) const
{
	mat4	res;

	res.data[0] = this->data[0] * scalar;	res.data[4] = this->data[4] * scalar;	 res.data[8] =  this->data[8] * scalar;	res.data[12] = this->data[12] * scalar;
	res.data[1] = this->data[1] * scalar;	res.data[5] = this->data[5] * scalar;	 res.data[9] =  this->data[9] * scalar;	res.data[13] = this->data[13] * scalar;
	res.data[2] = this->data[2] * scalar;	res.data[6] = this->data[6] * scalar;	res.data[10] = this->data[10] * scalar;	res.data[14] = this->data[14] * scalar;
	res.data[3] = this->data[3] * scalar;	res.data[7] = this->data[7] * scalar;	res.data[11] = this->data[11] * scalar;	res.data[15] = this->data[15] * scalar;

	return res;
}

matrix::mat4&	matrix::mat4::operator*=(const float scalar)
{
	*this = *this * scalar;

	return *this;
}

matrix::mat4	matrix::operator*(const float scalar, const mat4& rhs)
{
	return rhs * scalar;
}

matrix::mat4	matrix::mat4::operator/(const mat4& rhs) const
{
	return *this * invert(rhs);
}

matrix::mat4&	matrix::mat4::operator/=(const mat4& rhs)
{
	*this = *this / rhs;

	return *this;
}

bool	matrix::mat4::operator==(const mat4& rhs) const
{
	for (unsigned char i = 0; i < 16; i++)
	{
		if (this->data[i] != rhs.data[i])
			return false;
	}
	return true;
}

bool	matrix::mat4::operator!=(const mat4& rhs) const
{
	return !(*this == rhs);
}

void	matrix::mat4::transpose(void)
{
	mat4	tmp = *this;

	this->data[0] = tmp.data[0];  this->data[4] = tmp.data[1];  this->data[8] = tmp.data[2];   this->data[12] = tmp.data[3];
	this->data[1] = tmp.data[4];  this->data[5] = tmp.data[5];  this->data[9] = tmp.data[6];   this->data[13] = tmp.data[7];
	this->data[2] = tmp.data[8];  this->data[6] = tmp.data[9];  this->data[10] = tmp.data[10]; this->data[14] = tmp.data[11];
	this->data[3] = tmp.data[12]; this->data[7] = tmp.data[13]; this->data[11] = tmp.data[14]; this->data[15] = tmp.data[15];
}

void	matrix::mat4::scale(const vec3& vector)
{
	this->data[0] *= vector.x;  this->data[4] *= vector.y;  this->data[8] *= vector.z;
	this->data[1] *= vector.x;  this->data[5] *= vector.y;  this->data[9] *= vector.z;
	this->data[2] *= vector.x;  this->data[6] *= vector.y; this->data[10] *= vector.z;
	this->data[3] *= vector.x;  this->data[7] *= vector.y; this->data[11] *= vector.z;
}

std::ostream&	matrix::operator<<(std::ostream& os, const mat4& matrice)
{
	os << "/ " << matrice.data[0] << " " << matrice.data[4] << " " << matrice.data[8] << " " << matrice.data[12] << " \\" << std::endl;
	os << "| " << matrice.data[1] << " " << matrice.data[5] << " " << matrice.data[9] << " " << matrice.data[13] << " |" << std::endl;
	os << "| " << matrice.data[2] << " " << matrice.data[6] << " " << matrice.data[10] << " " << matrice.data[14] << " |" << std::endl;
	os << "\\ " << matrice.data[3] << " " << matrice.data[7] << " " << matrice.data[11] << " " << matrice.data[15] << " /" << std::endl;

	return os;
}

void	matrix::identity(mat4& matrice)
{
	matrice.data[0] = 1.0f;	matrice.data[4] = 0.0f;	 matrice.data[8] = 0.0f;	matrice.data[12] = 0.0f;
	matrice.data[1] = 0.0f;	matrice.data[5] = 1.0f;	 matrice.data[9] = 0.0f;	matrice.data[13] = 0.0f;
	matrice.data[2] = 0.0f;	matrice.data[6] = 0.0f;	matrice.data[10] = 1.0f;	matrice.data[14] = 0.0f;
	matrice.data[3] = 0.0f;	matrice.data[7] = 0.0f;	matrice.data[11] = 0.0f;	matrice.data[15] = 1.0f;
}

float	matrix::determinant(const mat4& matrice)
{
	float	det = 0.0f;
	float	s[6];
	float	c[6];

	s[0] = matrice.data[0] * matrice.data[5]  - matrice.data[4]  * matrice.data[1];
	s[1] = matrice.data[0] * matrice.data[9]  - matrice.data[8]  * matrice.data[1];
	s[2] = matrice.data[0] * matrice.data[13] - matrice.data[12] * matrice.data[1];
	s[3] = matrice.data[4] * matrice.data[9]  - matrice.data[8]  * matrice.data[5];
	s[4] = matrice.data[4] * matrice.data[13] - matrice.data[12] * matrice.data[5];
	s[5] = matrice.data[8] * matrice.data[13] - matrice.data[12] * matrice.data[9];

	c[0] = matrice.data[2]  * matrice.data[7]  - matrice.data[6]  * matrice.data[3];
	c[1] = matrice.data[2]  * matrice.data[11] - matrice.data[10] * matrice.data[3];
	c[2] = matrice.data[2]  * matrice.data[15] - matrice.data[14] * matrice.data[3];
	c[3] = matrice.data[6]  * matrice.data[11] - matrice.data[10] * matrice.data[7];
	c[4] = matrice.data[6]  * matrice.data[15] - matrice.data[14] * matrice.data[7];
	c[5] = matrice.data[10] * matrice.data[15] - matrice.data[14] * matrice.data[11];

	det  = s[0] * c[5];
	det -= s[1] * c[4];
	det += s[2] * c[3];
	det += s[3] * c[2];
	det -= s[4] * c[1];
	det += s[5] * c[0];

	return det;
}

static float	mat4_det_fast(float s[6], float c[6])
{
	float	det = 0.0f;

	det  = s[0] * c[5];
	det -= s[1] * c[4];
	det += s[2] * c[3];
	det += s[3] * c[2];
	det -= s[4] * c[1];
	det += s[5] * c[0];

	return det;
}

matrix::mat4	matrix::invert(const mat4& matrice)
{
	float	s[6];
	float	c[6];

	s[0] = matrice.data[0] * matrice.data[5]  -  matrice.data[4] * matrice.data[1];
	s[1] = matrice.data[0] * matrice.data[9]  -  matrice.data[8] * matrice.data[1];
	s[2] = matrice.data[0] * matrice.data[13] - matrice.data[12] * matrice.data[1];
	s[3] = matrice.data[4] * matrice.data[9]  -  matrice.data[8] * matrice.data[5];
	s[4] = matrice.data[4] * matrice.data[13] - matrice.data[12] * matrice.data[5];
	s[5] = matrice.data[8] * matrice.data[13] - matrice.data[12] * matrice.data[9];

	c[0] =  matrice.data[2] * matrice.data[7]  -  matrice.data[6] * matrice.data[3];
	c[1] =  matrice.data[2] * matrice.data[11] - matrice.data[10] * matrice.data[3];
	c[2] =  matrice.data[2] * matrice.data[15] - matrice.data[14] * matrice.data[3];
	c[3] =  matrice.data[6] * matrice.data[11] - matrice.data[10] * matrice.data[7];
	c[4] =  matrice.data[6] * matrice.data[15] - matrice.data[14] * matrice.data[7];
	c[5] = matrice.data[10] * matrice.data[15] - matrice.data[14] * matrice.data[11];

	float	det = mat4_det_fast(s, c);
	if (std::fabs(det) < 1e-6f)
		#ifdef DEBUG
			throw std::runtime_error("Matrice is not invertible");
		#else
			return matrice;
		#endif

	float	inv = 1.0f / det;
	mat4	res;

	res.data[0]  = ( matrice.data[5] * c[5] - matrice.data[9] * c[4] + matrice.data[13] * c[3]) * inv;
	res.data[1]  = (-matrice.data[1] * c[5] + matrice.data[9] * c[2] - matrice.data[13] * c[1]) * inv;
	res.data[2]  = ( matrice.data[1] * c[4] - matrice.data[5] * c[2] + matrice.data[13] * c[0]) * inv;
	res.data[3]  = (-matrice.data[1] * c[3] + matrice.data[5] * c[1] -  matrice.data[9] * c[0]) * inv;

	res.data[4]  = (-matrice.data[4] * c[5] + matrice.data[8] * c[4] - matrice.data[12] * c[3]) * inv;
	res.data[5]  = ( matrice.data[0] * c[5] - matrice.data[8] * c[2] + matrice.data[12] * c[1]) * inv;
	res.data[6]  = (-matrice.data[0] * c[4] + matrice.data[4] * c[2] - matrice.data[12] * c[0]) * inv;
	res.data[7]  = ( matrice.data[0] * c[3] - matrice.data[4] * c[1] +  matrice.data[8] * c[0]) * inv;

	res.data[8]  = ( matrice.data[7] * s[5] - matrice.data[11] * s[4] + matrice.data[15] * s[3]) * inv;
	res.data[9]  = (-matrice.data[3] * s[5] + matrice.data[11] * s[2] - matrice.data[15] * s[1]) * inv;
	res.data[10] = ( matrice.data[3] * s[4] -  matrice.data[7] * s[2] + matrice.data[15] * s[0]) * inv;
	res.data[11] = (-matrice.data[3] * s[3] +  matrice.data[7] * s[1] - matrice.data[11] * s[0]) * inv;

	res.data[12] = (-matrice.data[6] * s[5] + matrice.data[10] * s[4] - matrice.data[14] * s[3]) * inv;
	res.data[13] = ( matrice.data[2] * s[5] - matrice.data[10] * s[2] + matrice.data[14] * s[1]) * inv;
	res.data[14] = (-matrice.data[2] * s[4] +  matrice.data[6] * s[2] - matrice.data[14] * s[0]) * inv;
	res.data[15] = ( matrice.data[2] * s[3] -  matrice.data[6] * s[1] + matrice.data[10] * s[0]) * inv;

	return res;
}

matrix::mat4	matrix::transpose(const mat4& matrice)
{
	mat4	res = matrice;

	res.transpose();
	return res;
}

matrix::mat4	matrix::scale(const mat4& matrice, const vec3& vector)
{
	mat4	res = matrice;

	res.scale(vector);
	return res;
}

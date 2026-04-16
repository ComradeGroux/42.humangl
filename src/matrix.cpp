#include "matrix.hpp"

#include <stdexcept>
#include <cmath>

matrix::vec3::vec3(void) : x(0.0f), y(0.0f), z(0.0f)
{
}

matrix::vec3::vec3(float data) : x(data), y(data), z(data)
{
}

matrix::vec3::vec3(float x, float y, float z) : x(x), y(y), z(z)
{
}

matrix::vec3::vec3(const vec3& rhs) : x(rhs.x), y(rhs.y), z(rhs.z)
{
}

matrix::vec3&	matrix::vec3::operator=(const vec3& rhs)
{
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;

	return *this;
}

matrix::vec3	matrix::vec3::operator+(const vec3& rhs) const
{
	vec3	res;

	res.x = this->x + rhs.x;
	res.y = this->y + rhs.y;
	res.z = this->z + rhs.z;

	return res;
}

matrix::vec3	matrix::vec3::operator-(const vec3& rhs) const
{
	vec3	res;

	res.x = this->x - rhs.x;
	res.y = this->y - rhs.y;
	res.z = this->z - rhs.z;

	return res;
}

matrix::vec3	matrix::vec3::operator*(const vec3& rhs) const
{
	vec3	res;

	res.x = this->x * rhs.x;
	res.y = this->y * rhs.y;
	res.z = this->z * rhs.z;

	return res;
}

matrix::vec3	matrix::vec3::operator*(const float scalar) const
{
	return matrix::scale(*this, scalar);
}

matrix::vec3	matrix::vec3::operator/(const vec3& rhs) const
{
	vec3	res;

	res.x = this->x / rhs.x;
	res.y = this->y / rhs.y;
	res.z = this->z / rhs.z;

	return res;
}

matrix::vec3	matrix::vec3::operator/(const float scalar) const
{
	vec3	res;

	res.x = this->x / scalar;
	res.y = this->y / scalar;
	res.z = this->z / scalar;

	return res;
}

void	matrix::vec3::scale(float scalar)
{
	this->x *= scalar;
	this->y *= scalar;
	this->z *= scalar;
}

float	matrix::vec3::length(void) const
{
	return std::sqrt(std::pow(this->x, 2.0f) + std::pow(this->y, 2.0f) + std::pow(this->z, 2.0f));
}

void	matrix::vec3::normalize(void)
{
	float	len = this->length();

	this->x = this->x / len;
	this->y = this->y / len;
	this->z = this->z / len;
}

matrix::vec3	matrix::scale(const vec3 vector, float scalar)
{
	vec3	res = vector;

	res.scale(scalar);

	return res;
}

float	matrix::dot(const vec3 lhs, const vec3 rhs)
{
	float	ret = 0.0f;

	ret += lhs.x * rhs.x;
	ret += lhs.y * rhs.y;
	ret += lhs.z * rhs.z;

	return ret;
}

matrix::vec3	matrix::cross(const vec3 lhs, const vec3 rhs)
{
	vec3	ret;

	ret.x = lhs.y * rhs.z - lhs.z * rhs.y;
	ret.y = lhs.z * rhs.x - lhs.x * rhs.z;
	ret.z = lhs.x * rhs.y - lhs.y * rhs.x;

	return ret;
}



matrix::vec4::vec4(void) : x(0.0f), y(0.0f), z(0.0f), w(1.0f)
{
}

matrix::vec4::vec4(float data) : x(data), y(data), z(data), w(data)
{
}

matrix::vec4::vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w)
{
}

matrix::vec4::vec4(const vec4& rhs) : x(rhs.x), y(rhs.y), z(rhs.z), w(rhs.w)
{
}

matrix::vec4&	matrix::vec4::operator=(const vec4& rhs)
{
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;
	w = rhs.w;

	return *this;
}

matrix::vec4	matrix::vec4::operator+(const vec4& rhs) const
{
	vec4	res;

	res.x = this->x + rhs.x;
	res.y = this->y + rhs.y;
	res.z = this->z + rhs.z;
	res.w = this->w + rhs.w;

	return res;
}

matrix::vec4	matrix::vec4::operator-(const vec4& rhs) const
{
	vec4	res;

	res.x = this->x - rhs.x;
	res.y = this->y - rhs.y;
	res.z = this->z - rhs.z;
	res.w = this->w - rhs.w;

	return res;
}

matrix::vec4	matrix::vec4::operator*(const vec4& rhs) const
{
	vec4	res;

	res.x = this->x * rhs.x;
	res.y = this->y * rhs.y;
	res.z = this->z * rhs.z;
	res.w = this->w * rhs.w;

	return rhs;
}

matrix::vec4	matrix::vec4::operator*(const float scalar) const
{
	return matrix::scale(*this, scalar);
}

matrix::vec4	matrix::vec4::operator/(const vec4& rhs) const
{
	vec4	res;

	res.x = this->x / rhs.x;
	res.y = this->y / rhs.y;
	res.z = this->z / rhs.z;
	res.w = this->w / rhs.w;

	return res;
}

matrix::vec4	matrix::vec4::operator/(const float scalar) const
{
	vec4	res;

	res.x = this->x / scalar;
	res.y = this->y / scalar;
	res.z = this->z / scalar;
	res.w = this->w / scalar;

	return res;
}

void	matrix::vec4::scale(float scalar)
{
	x *= scalar;
	y *= scalar;
	z *= scalar;
	w *= scalar;
}

float	matrix::vec4::length(void) const
{
	return std::sqrt(pow(this->x, 2.0f) + pow(this->y, 2.0f) + pow(this->z, 2.0f) + pow(this->w, 2.0f));
}

void	matrix::vec4::normalize(void)
{
	float	len = this->length();

	this->x = this->x / len;
	this->y = this->y / len;
	this->z = this->z / len;
	this->w = this->w / len;
}

matrix::vec4	matrix::scale(const vec4 vector, float scalar)
{
	vec4	res = vector;

	res.scale(scalar);

	return res;
}

float	matrix::dot(const vec4 lhs, const vec4 rhs)
{
	return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w;
}

matrix::vec3	matrix::cross(const vec4 lhs, const vec4 rhs)
{
	vec3	tempA(lhs.x / lhs.w, lhs.y / lhs.w, lhs.z / lhs.w);
	vec3	tempB(rhs.x / rhs.w, rhs.y / rhs.w, rhs.z / rhs.w);

	return cross(tempA, tempB);
}





matrix::mat3::mat3(void)
{
	for (unsigned char i = 0; i < 9; i++)
		data[i] = 0.0f;
}

matrix::mat3::mat3(const mat3& rhs)
{
	*this = rhs;
}

matrix::mat3&	matrix::mat3::operator=(const mat3& rhs)
{
	for (unsigned char i = 0; i < 9; i++)
		data[i] = rhs.data[i];

	return *this;
}

void	matrix::identity(mat3& matrice)
{
	matrice.data[0] = 1.0f;	matrice.data[3] = 0.0f;	matrice.data[6] = 0.0f;
	matrice.data[1] = 0.0f;	matrice.data[4] = 1.0f;	matrice.data[7] = 0.0f;
	matrice.data[2] = 0.0f;	matrice.data[5] = 0.0f;	matrice.data[8] = 1.0f;
}

float	matrix::determinant(const mat3 matrice)
{
	float	det = 0.0f;

	det  = matrice.data[0] * (matrice.data[4] * matrice.data[8] - matrice.data[7] * matrice.data[5]);
	det -= matrice.data[3] * (matrice.data[1] * matrice.data[8] - matrice.data[7] * matrice.data[2]);
	det += matrice.data[6] * (matrice.data[1] * matrice.data[5] - matrice.data[4] * matrice.data[2]);

	return det;
}

matrix::mat3	matrix::invert(const mat3 matrice)
{
	float	det = determinant(matrice);
	if (det == 0.0f)
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

matrix::mat3	matrix::mat3::operator+(const mat3& rhs) const
{
	mat3	res;

	res.data[0] = this->data[0] + rhs.data[0];	res.data[3] = this->data[3] + rhs.data[3];	res.data[6] = this->data[6] + rhs.data[6];
	res.data[1] = this->data[1] + rhs.data[1];	res.data[4] = this->data[4] + rhs.data[4];	res.data[7] = this->data[7] + rhs.data[7];
	res.data[2] = this->data[2] + rhs.data[2];	res.data[5] = this->data[5] + rhs.data[5];	res.data[8] = this->data[8] + rhs.data[8];

	return res;
}

matrix::mat3	matrix::mat3::operator-(const mat3& rhs) const
{
	mat3	res;

	res.data[0] = this->data[0] - rhs.data[0];	res.data[3] = this->data[3] - rhs.data[3];	res.data[6] = this->data[6] - rhs.data[6];
	res.data[1] = this->data[1] - rhs.data[1];	res.data[4] = this->data[4] - rhs.data[4];	res.data[7] = this->data[7] - rhs.data[7];
	res.data[2] = this->data[2] - rhs.data[2];	res.data[5] = this->data[5] - rhs.data[5];	res.data[8] = this->data[8] - rhs.data[8];

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

matrix::mat3	matrix::mat3::operator/(const mat3& rhs) const
{
	return *this * invert(rhs);
}




matrix::mat4::mat4(void)
{
	for (unsigned char i = 0; i < 16; i++)
		data[i] = 0.0f;
}

matrix::mat4::mat4(const mat4& rhs)
{
	*this = rhs;
}

matrix::mat4&	matrix::mat4::operator=(const mat4& rhs)
{
	for (unsigned char i = 0; i < 16; i++)
		data[i] = rhs.data[i];

	return *this;
}

void	matrix::identity(mat4& matrice)
{
	matrice.data[0] = 1.0f;	matrice.data[4] = 0.0f;	 matrice.data[8] = 0.0f;	matrice.data[12] = 0.0f;
	matrice.data[1] = 0.0f;	matrice.data[5] = 1.0f;	 matrice.data[9] = 0.0f;	matrice.data[13] = 0.0f;
	matrice.data[2] = 0.0f;	matrice.data[6] = 0.0f;	matrice.data[10] = 1.0f;	matrice.data[14] = 0.0f;
	matrice.data[3] = 0.0f;	matrice.data[7] = 0.0f;	matrice.data[11] = 0.0f;	matrice.data[15] = 1.0f;
}

float	matrix::determinant(const mat4 matrice)
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

matrix::mat4	matrix::invert(const mat4 matrice)
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
	if (det == 0.0f)
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

matrix::mat4	matrix::mat4::operator+(const mat4& rhs) const
{
	mat4	res;

	res.data[0] = this->data[0] + rhs.data[0];	res.data[4] = this->data[4] + rhs.data[4];	 res.data[8] =  this->data[8] + rhs.data[8];	res.data[12] = this->data[12] + rhs.data[12];
	res.data[1] = this->data[1] + rhs.data[1];	res.data[5] = this->data[5] + rhs.data[5];	 res.data[9] =  this->data[9] + rhs.data[9];	res.data[13] = this->data[13] + rhs.data[13];
	res.data[2] = this->data[2] + rhs.data[2];	res.data[6] = this->data[6] + rhs.data[6];	res.data[10] = this->data[10] + rhs.data[10];	res.data[14] = this->data[14] + rhs.data[14];
	res.data[3] = this->data[3] + rhs.data[3];	res.data[7] = this->data[7] + rhs.data[7];	res.data[11] = this->data[11] + rhs.data[11];	res.data[15] = this->data[15] + rhs.data[15];

	return res;
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

matrix::vec4	matrix::mat4::operator*(const vec4& rhs) const
{
	vec4	res;

	res.x = this->data[0] * rhs.x + this->data[4] * rhs.y +  this->data[8] * rhs.z + this->data[12] * rhs.w;
	res.y = this->data[1] * rhs.x + this->data[5] * rhs.y +  this->data[9] * rhs.z + this->data[13] * rhs.w;
	res.z = this->data[2] * rhs.x + this->data[6] * rhs.y + this->data[10] * rhs.z + this->data[14] * rhs.w;
	res.w = this->data[3] * rhs.x + this->data[7] * rhs.y + this->data[11] * rhs.z + this->data[15] * rhs.w;

	return res;
}

matrix::mat4	matrix::mat4::operator/(const mat4& rhs) const
{
	return *this * invert(rhs);
}




float matrix::deg_to_radians(float degrees)
{
	return degrees * 3.14159265358979323846f / 180.0f;
}

float matrix::rad_to_degrees(float radians)
{
	return radians * 180.0f / 3.14159265358979323846f;
}

#include "vec3.hpp"

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

matrix::vec3::vec3(const vec4& rhs) : x(rhs.x / rhs.w), y(rhs.y / rhs.w), z(rhs.z / rhs.w)
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

matrix::vec3&	matrix::vec3::operator+=(const vec3& rhs)
{
	*this = *this + rhs;

	return *this;
}

matrix::vec3	matrix::vec3::operator-(const vec3& rhs) const
{
	vec3	res;

	res.x = this->x - rhs.x;
	res.y = this->y - rhs.y;
	res.z = this->z - rhs.z;

	return res;
}

matrix::vec3&	matrix::vec3::operator-=(const vec3& rhs)
{
	*this = *this - rhs;

	return *this;
}

matrix::vec3	matrix::vec3::operator-(void) const
{
	vec3	res;

	res.x = -(this->x);
	res.y = -(this->y);
	res.z = -(this->z);

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

matrix::vec3&	matrix::vec3::operator*=(const vec3& rhs)
{
	*this = *this * rhs;

	return *this;
}

matrix::vec3	matrix::vec3::operator*(const float scalar) const
{
	return matrix::scale(*this, scalar);
}

matrix::vec3&	matrix::vec3::operator*=(const float scalar)
{
	*this = *this * scalar;

	return *this;
}

matrix::vec3	matrix::vec3::operator/(const vec3& rhs) const
{
	vec3	res;

	res.x = this->x / rhs.x;
	res.y = this->y / rhs.y;
	res.z = this->z / rhs.z;

	return res;
}

matrix::vec3&	matrix::vec3::operator/=(const vec3& rhs)
{
	*this = *this / rhs;

	return *this;
}

matrix::vec3	matrix::vec3::operator/(const float scalar) const
{
	vec3	res;

	res.x = this->x / scalar;
	res.y = this->y / scalar;
	res.z = this->z / scalar;

	return res;
}

matrix::vec3&	matrix::vec3::operator/=(const float scalar)
{
	*this = *this / scalar;

	return *this;
}

bool	matrix::vec3::operator==(const vec3& rhs) const
{
	if (this->x == rhs.x && this->y == rhs.y && this->z == rhs.z)
		return true;
	else
		return false;
}

bool	matrix::vec3::operator!=(const vec3& rhs) const
{
	return !(*this == rhs);
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

std::ostream&	matrix::operator<<(std::ostream& os, const vec3& vector)
{
	os << "x: " << vector.x << " | y: " << vector.y << " | z: " << vector.z;

	return os;
}

matrix::vec3	matrix::scale(const vec3 vector, float scalar)
{
	vec3	res = vector;

	res.scale(scalar);

	return res;
}

matrix::vec3	matrix::normalize(const vec3 vector)
{
	vec3	res;
	float	len = vector.length();

	res.x = vector.x / len;
	res.y = vector.y / len;
	res.z = vector.z / len;

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

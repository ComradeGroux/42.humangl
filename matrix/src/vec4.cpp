#include "vec4.hpp"

#include <cmath>

matrix::vec4::vec4(void) : x(0.0f), y(0.0f), z(0.0f), w(1.0f)
{
}

matrix::vec4::vec4(float data) : x(data), y(data), z(data), w(data)
{
}

matrix::vec4::vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w)
{
}

matrix::vec4::vec4(const vec3& rhs, float w) : x(rhs.x), y(rhs.y), z(rhs.z), w(w)
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
	vec4	res = *this;

	res.x += rhs.x;
	res.y += rhs.y;
	res.z += rhs.z;
	res.w += rhs.w;

	return res;
}

matrix::vec4&	matrix::vec4::operator+=(const vec4& rhs)
{
	*this = *this + rhs;

	return *this;
}

matrix::vec4	matrix::vec4::operator-(const vec4& rhs) const
{
	vec4	res = *this;

	res.x -= rhs.x;
	res.y -= rhs.y;
	res.z -= rhs.z;
	res.w -= rhs.w;

	return res;
}

matrix::vec4&	matrix::vec4::operator-=(const vec4& rhs)
{
	*this = *this - rhs;

	return *this;
}

matrix::vec4	matrix::vec4::operator-(void) const
{
	vec4	res;

	res.x = -(this->x);
	res.y = -(this->y);
	res.z = -(this->z);
	res.w = -(this->w);

	return res;
}

matrix::vec4	matrix::vec4::operator*(const vec4& rhs) const
{
	vec4	res = *this;

	res.x *= rhs.x;
	res.y *= rhs.y;
	res.z *= rhs.z;
	res.w *= rhs.w;

	return res;
}

matrix::vec4&	matrix::vec4::operator*=(const vec4& rhs)
{
	*this = *this * rhs;

	return *this;
}

matrix::vec4	matrix::vec4::operator*(const float scalar) const
{
	return matrix::scale(*this, scalar);
}

matrix::vec4&	matrix::vec4::operator*=(const float scalar)
{
	*this = *this * scalar;

	return *this;
}

matrix::vec4	matrix::operator*(const float scalar, const vec4& rhs)
{
	return rhs * scalar;
}

matrix::vec4	matrix::vec4::operator/(const vec4& rhs) const
{
	vec4	res = *this;

	if (rhs.x > 0.0f)
		res.x /= rhs.x;
	if (rhs.y > 0.0f)
		res.y /= rhs.y;
	if (rhs.z > 0.0f)
		res.z /= rhs.z;
	if (rhs.w > 0.0f)
		res.w /= rhs.w;

	return res;
}

matrix::vec4&	matrix::vec4::operator/=(const vec4& rhs)
{
	*this = *this / rhs;

	return *this;
}

matrix::vec4	matrix::vec4::operator/(const float scalar) const
{
	vec4	res = *this;

	if (scalar > 0.0f)
	{
		res.x /= scalar;
		res.y /= scalar;
		res.z /= scalar;
		res.w /= scalar;
	}

	return res;
}

matrix::vec4&	matrix::vec4::operator/=(const float scalar)
{
	*this = *this / scalar;

	return *this;
}

bool	matrix::vec4::operator==(const vec4& rhs) const
{
	if (this->x == rhs.x && this->y == rhs.y && this->z == rhs.z && this->w == rhs.w)
		return true;
	else
		return false;
}

bool	matrix::vec4::operator!=(const vec4& rhs) const
{
	return !(*this == rhs);
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
	return std::sqrt(this->x * this->x + this->y * this->y + this->z * this->z + this->w * this->w);
}

void	matrix::vec4::normalize(void)
{
	float	len = this->length();
	if (len > 0.0f)
	{
		this->x = this->x / len;
		this->y = this->y / len;
		this->z = this->z / len;
		this->w = this->w / len;
	}
}

std::ostream&	matrix::operator<<(std::ostream& os, const vec4& vector)
{
	os << "x: " << vector.x << " | y: " << vector.y << " | z: " << vector.z << " | w: " << vector.w;

	return os;
}

matrix::vec4	matrix::scale(const vec4& vector, float scalar)
{
	vec4	res = vector;

	res.scale(scalar);

	return res;
}

matrix::vec4	matrix::normalize(const vec4& vector)
{
	vec4	res = vector;

	float	len = res.length();
	if (len > 0.0f)
	{
		res.x /= len;
		res.y /= len;
		res.z /= len;
		res.w /= len;
	}

	return res;
}

float	matrix::dot(const vec4& lhs, const vec4& rhs)
{
	return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w;
}

matrix::vec3	matrix::cross(const vec4& lhs, const vec4& rhs)
{
	vec3	tempA(lhs);
	vec3	tempB(rhs);

	return cross(tempA, tempB);
}

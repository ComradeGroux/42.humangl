#include "vec2.hpp"

#include <cmath>

matrix::vec2::vec2(void) : x(0.0f), y(0.0f)
{
}

matrix::vec2::vec2(float data) : x(data), y(data)
{
}

matrix::vec2::vec2(float x, float y) : x(x), y(y)
{
}

matrix::vec2::vec2(const vec2& rhs) : x(rhs.x), y(rhs.y)
{
}

matrix::vec2::vec2(const vec3& rhs) : x(rhs.x), y(rhs.y)
{
}

matrix::vec2::vec2(const vec4& rhs)
{
	if (std::fabs(rhs.w) > 1e-6f)
	{
		x = rhs.x / rhs.w;
		y = rhs.y / rhs.w;
	}
}

matrix::vec2&	matrix::vec2::operator=(const vec2& rhs)
{
	x = rhs.x;
	y = rhs.y;

	return *this;
}

matrix::vec2	matrix::vec2::operator+(const vec2& rhs) const
{
	vec2	res = *this;

	res.x += rhs.x;
	res.y += rhs.y;

	return res;
}

matrix::vec2&	matrix::vec2::operator+=(const vec2& rhs)
{
	*this = *this + rhs;

	return *this;
}

matrix::vec2	matrix::vec2::operator-(const vec2& rhs) const
{
	vec2	res = *this;

	res.x -= rhs.x;
	res.y -= rhs.y;

	return res;
}

matrix::vec2&	matrix::vec2::operator-=(const vec2& rhs)
{
	*this = *this - rhs;

	return *this;
}

matrix::vec2		matrix::vec2::operator-(void) const
{
	vec2	res;

	res.x -= this->x;
	res.y -= this->y;

	return res;
}

matrix::vec2		matrix::vec2::operator*(const matrix::vec2& rhs) const
{
	vec2	res = *this;

	res.x *= rhs.x;
	res.y *= rhs.y;

	return res;
}

matrix::vec2&		matrix::vec2::operator*=(const matrix::vec2& rhs)
{
	*this = *this * rhs;

	return *this;
}

matrix::vec2		matrix::vec2::operator*(const float scalar) const
{
	vec2	res = *this;

	res.x *= scalar;
	res.y *= scalar;

	return res;
}

matrix::vec2&		matrix::vec2::operator*=(const float scalar)
{
	*this = *this * scalar;

	return *this;
}

matrix::vec2	matrix::operator*(const float scalar, const matrix::vec2& rhs)
{
	return rhs * scalar;
}

matrix::vec2		matrix::vec2::operator/(const matrix::vec2& rhs) const
{
	vec2	res = *this;

	if (std::fabs(rhs.x) > 1e-6f)
		res.x /= rhs.x;
	if (std::fabs(rhs.y) > 1e-6f)
		res.y /= rhs.y;

	return res;
}

matrix::vec2&		matrix::vec2::operator/=(const matrix::vec2& rhs)
{
	*this = *this / rhs;

	return *this;
}

matrix::vec2		matrix::vec2::operator/(const float scalar) const
{
	vec2	res = *this;

	if (std::fabs(scalar) > 1e-6f)
	{
		res.x /= scalar;
		res.y /= scalar;
	}

	return res;
}

matrix::vec2&		matrix::vec2::operator/=(const float scalar)
{
	*this = *this / scalar;

	return *this;
}


bool	matrix::vec2::operator==(const matrix::vec2& rhs) const
{
	if (this->x == rhs.x && this->y == rhs.y)
		return true;
	else
		return false;
}

bool	matrix::vec2::operator!=(const matrix::vec2& rhs) const
{
	return !(*this == rhs);
}


void	matrix::vec2::scale(float scalar)
{
	this->x *= scalar;
	this->y *= scalar;
}

float	matrix::vec2::length(void) const
{
	return std::sqrt(this->x * this->x + this->y * this->y);
}

void	matrix::vec2::normalize(void)
{
	float	len = this->length();
	if (len > 0.0f)
	{
		this->x /= len;
		this->y /= len;
	}
}

std::ostream&	matrix::operator<<(std::ostream& os, const vec2& vector)
{
	os << "x: " << vector.x << " | y: " << vector.y;

	return os;
}

matrix::vec2	matrix::scale(const vec2& vector, float scalar)
{
	vec2	res = vector;

	res.scale(scalar);

	return res;
}

float	matrix::length(const vec2& vector)
{
	return vector.length();
}

matrix::vec2	matrix::normalize(const vec2& vector)
{
	vec2	res = vector;

	res.normalize();

	return res;
}

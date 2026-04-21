#include "vec2.hpp"
#include "utils.hpp"

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

matrix::vec2::vec2(const vec4& rhs) : x(rhs.x), y(rhs.y)
{
}

matrix::vec2&	matrix::vec2::operator=(const vec2& rhs)
{
	x = rhs.x;
	y = rhs.y;

	return *this;
}

matrix::vec2	matrix::vec2::fromHomogeneous(const vec4& vector)
{
	vec2	res(vector);

	if (std::fabs(vector.w) > 1e-6f)
	{
		res.x /= vector.w;
		res.y /= vector.w;
	}

	return res;
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

	res.x = -this->x;
	res.y = -this->y;

	return res;
}

matrix::vec2	matrix::vec2::operator*(const matrix::vec2& rhs) const
{
	vec2	res = *this;

	res.x *= rhs.x;
	res.y *= rhs.y;

	return res;
}

matrix::vec2&	matrix::vec2::operator*=(const matrix::vec2& rhs)
{
	*this = *this * rhs;

	return *this;
}

matrix::vec2	matrix::vec2::operator*(const matrix::mat2& rhs) const
{
	vec2	res;

	res.x = this->x * rhs.data[0] + this->y * rhs.data[2];
	res.y = this->x * rhs.data[1] + this->y * rhs.data[3];

	return res;
}

matrix::vec2&	matrix::vec2::operator*=(const matrix::mat2& rhs)
{
	*this = *this * rhs;

	return *this;
}

matrix::vec2	matrix::vec2::operator*(const float scalar) const
{
	vec2	res = *this;

	res.x *= scalar;
	res.y *= scalar;

	return res;
}

matrix::vec2&	matrix::vec2::operator*=(const float scalar)
{
	*this = *this * scalar;

	return *this;
}

matrix::vec2	matrix::operator*(const float scalar, const matrix::vec2& rhs)
{
	return rhs * scalar;
}

matrix::vec2	matrix::vec2::operator/(const matrix::vec2& rhs) const
{
	vec2	res = *this;

	if (std::fabs(rhs.x) > 1e-6f)
		res.x /= rhs.x;
	if (std::fabs(rhs.y) > 1e-6f)
		res.y /= rhs.y;

	return res;
}

matrix::vec2&	matrix::vec2::operator/=(const matrix::vec2& rhs)
{
	*this = *this / rhs;

	return *this;
}

matrix::vec2	matrix::vec2::operator/(const float scalar) const
{
	vec2	res = *this;

	if (std::fabs(scalar) > 1e-6f)
	{
		res.x /= scalar;
		res.y /= scalar;
	}

	return res;
}

matrix::vec2&	matrix::vec2::operator/=(const float scalar)
{
	*this = *this / scalar;

	return *this;
}


bool	matrix::vec2::operator==(const matrix::vec2& rhs) const
{
	if (std::fabs(x - rhs.x) < 1e-6f && std::fabs(y - rhs.y) < 1e-6f)
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

void	matrix::vec2::clamp(float min, float max)
{
	x = matrix::clamp(x, min, max);
	y = matrix::clamp(y, min, max);
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

matrix::vec2	matrix::clamp(const vec2& vector, float min, float max)
{
	vec2	res = vector;

	res.clamp(min, max);

	return res;
}

float	matrix::dot(const vec2& lhs, const vec2& rhs)
{
	float	res = 0;

	res += lhs.x * rhs.x;
	res += lhs.y * rhs.y;

	return res;
}

float	matrix::cross(const vec2& lhs, const vec2& rhs)
{
	return lhs.x * rhs.y - lhs.y * rhs.x;
}

matrix::vec2	matrix::reflect(const vec2& vector, const vec2& normal)
{
	vec2	normalizedNormal = normalize(normal);

	return vector - 2 * dot(vector, normalizedNormal) * normalizedNormal;
}

matrix::vec2	matrix::lerp(const vec2& a, const vec2& b, float t)
{
	vec2	res;

	res.x = a.x + t * (b.x - a.x);
	res.y = a.y + t * (b.y - a.y);

	return res;
}

#include "vec3.hpp"
#include "utils.hpp"

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

matrix::vec3::vec3(const vec4& rhs) : x(rhs.x), y(rhs.y), z(rhs.z)
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
	vec3	res = *this;

	res.x += rhs.x;
	res.y += rhs.y;
	res.z += rhs.z;

	return res;
}

matrix::vec3&	matrix::vec3::operator+=(const vec3& rhs)
{
	*this = *this + rhs;

	return *this;
}

matrix::vec3	matrix::vec3::operator-(const vec3& rhs) const
{
	vec3	res = *this;

	res.x -= rhs.x;
	res.y -= rhs.y;
	res.z -= rhs.z;

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
	vec3	res = *this;

	res.x *= rhs.x;
	res.y *= rhs.y;
	res.z *= rhs.z;

	return res;
}

matrix::vec3&	matrix::vec3::operator*=(const vec3& rhs)
{
	*this = *this * rhs;

	return *this;
}

matrix::vec3	matrix::vec3::operator*(const mat3& rhs) const
{
	vec3	res;

	res.x = this->x * rhs.data[0] + this->y * rhs.data[3] + this->z * rhs.data[6];
	res.y = this->x * rhs.data[1] + this->y * rhs.data[4] + this->z * rhs.data[7];
	res.z = this->x * rhs.data[2] + this->y * rhs.data[5] + this->z * rhs.data[8];

	return res;
}

matrix::vec3&	matrix::vec3::operator*=(const mat3& rhs)
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

matrix::vec3	operator*(const float scalar, const matrix::vec3& rhs)
{
	return rhs * scalar;
}

matrix::vec3	matrix::vec3::operator/(const vec3& rhs) const
{
	vec3	res = *this;

	if (std::fabs(rhs.x) > 1e-6f)
		res.x /= rhs.x;
	if (std::fabs(rhs.y) > 1e-6f)
		res.y /= rhs.y;
	if (std::fabs(rhs.z) > 1e-6f)
		res.z /= rhs.z;

	return res;
}

matrix::vec3&	matrix::vec3::operator/=(const vec3& rhs)
{
	*this = *this / rhs;

	return *this;
}

matrix::vec3	matrix::vec3::operator/(const float scalar) const
{
	vec3	res = *this;

	if (std::fabs(scalar) > 1e-6f)
	{
		res.x /= scalar;
		res.y /= scalar;
		res.z /= scalar;
	}

	return res;
}

matrix::vec3&	matrix::vec3::operator/=(const float scalar)
{
	*this = *this / scalar;

	return *this;
}

bool	matrix::vec3::operator==(const vec3& rhs) const
{
	if (std::fabs(x - rhs.x) < 1e-6f && std::fabs(y - rhs.y) < 1e-6f && std::fabs(z - rhs.z) < 1e-6f)
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
	return std::sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}

void	matrix::vec3::normalize(void)
{
	float	len = this->length();
	if (len > 0.0f)
	{
		this->x /= len;
		this->y /= len;
		this->z /= len;
	}
}

void	matrix::vec3::clamp(float min, float max)
{
	x = matrix::clamp(x, min, max);
	y = matrix::clamp(y, min, max);
	z = matrix::clamp(z, min, max);
}

matrix::vec2	matrix::vec3::xy(void) const
{
	return vec2(this->x, this->y);
}

std::ostream&	matrix::operator<<(std::ostream& os, const vec3& vector)
{
	os << "x: " << vector.x << " | y: " << vector.y << " | z: " << vector.z;

	return os;
}

matrix::vec3	matrix::vec3::fromHomogeneous(const vec4& vector)
{
	vec3	res(vector);

	if (std::fabs(vector.w) > 1e-6f)
	{
		res.x /= vector.w;
		res.y /= vector.w;
		res.z /= vector.w;
	}

	return res;
}

matrix::vec3	matrix::scale(const vec3& vector, float scalar)
{
	vec3	res = vector;

	res.scale(scalar);

	return res;
}

float	matrix::length(const vec3& vector)
{
	return vector.length();
}

matrix::vec3	matrix::normalize(const vec3& vector)
{
	vec3	res = vector;

	float	len = res.length();
	if (len > 0.0f)
	{
		res.x /= len;
		res.y /= len;
		res.z /= len;
	}

	return res;
}

matrix::vec3	matrix::clamp(const vec3& vector, float min, float max)
{
	vec3	res = vector;

	res.clamp(min, max);

	return res;
}

float	matrix::dot(const vec3& lhs, const vec3& rhs)
{
	float	ret = 0.0f;

	ret += lhs.x * rhs.x;
	ret += lhs.y * rhs.y;
	ret += lhs.z * rhs.z;

	return ret;
}

matrix::vec3	matrix::cross(const vec3& lhs, const vec3& rhs)
{
	vec3	ret;

	ret.x = lhs.y * rhs.z - lhs.z * rhs.y;
	ret.y = lhs.z * rhs.x - lhs.x * rhs.z;
	ret.z = lhs.x * rhs.y - lhs.y * rhs.x;

	return ret;
}

matrix::vec3	matrix::reflect(const vec3& vector, const vec3& normal)
{
	vec3	normalizedNormal = normalize(normal);

	return vector - 2 * dot(vector, normalizedNormal) * normalizedNormal;
}

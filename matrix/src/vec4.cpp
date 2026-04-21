#include "vec4.hpp"
#include "utils.hpp"

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

matrix::vec4	matrix::vec4::operator*(const mat4& rhs) const
{
	vec4	res;

	res.x = this->x * rhs.data[0] + this->y * rhs.data[4] + this->z * rhs.data[8] + this->w * rhs.data[12];
	res.y = this->x * rhs.data[1] + this->y * rhs.data[5] + this->z * rhs.data[9] + this->w * rhs.data[13];
	res.z = this->x * rhs.data[2] + this->y * rhs.data[6] + this->z * rhs.data[10] + this->w * rhs.data[14];
	res.w = this->x * rhs.data[3] + this->y * rhs.data[7] + this->z * rhs.data[11] + this->w * rhs.data[15];

	return res;
}

matrix::vec4&	matrix::vec4::operator*=(const mat4& rhs)
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

	if (std::fabs(rhs.x) > 1e-6f)
		res.x /= rhs.x;
	if (std::fabs(rhs.y) > 1e-6f)
		res.y /= rhs.y;
	if (std::fabs(rhs.z) > 1e-6f)
		res.z /= rhs.z;
	if (std::fabs(rhs.w) > 1e-6f)
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

	if (std::fabs(scalar) > 1e-6f)
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
	if (std::fabs(x - rhs.x) < 1e-6f && std::fabs(y - rhs.y) < 1e-6f && std::fabs(z - rhs.z) < 1e-6f && std::fabs(w - rhs.w) < 1e-6f)
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

void	matrix::vec4::clamp(float min, float max)
{
	x = matrix::clamp(x, min, max);
	y = matrix::clamp(y, min, max);
	z = matrix::clamp(z, min, max);
	w = matrix::clamp(w, min, max);
}

matrix::vec3	matrix::vec4::xyz(void) const
{
	return vec3(*this);
}

matrix::vec2	matrix::vec4::xy(void) const
{
	return vec2(*this);
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

float	matrix::length(const vec4& vector)
{
	return vector.length();
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

matrix::vec4	matrix::clamp(const vec4& vector, float min, float max)
{
	vec4	res = vector;

	res.clamp(min, max);

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

matrix::vec4	matrix::reflect(const vec4& vector, const vec4& normal)
{
	vec4	normalizedNormal = normalize(normal);

	return vector - 2 * dot(vector, normalizedNormal) * normalizedNormal;
}

matrix::vec4	matrix::lerp(const vec4&a, const vec4& b, float t)
{
	vec4	res;

	res.x = a.x + t * (b.x - a.x);
	res.y = a.y + t * (b.y - a.y);
	res.z = a.z + t * (b.z - a.z);
	res.w = a.w + t * (b.w - a.w);

	return res;	
}

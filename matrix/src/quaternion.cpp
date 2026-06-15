#include "quaternion.hpp"

#include "utils.hpp"

#include <cmath>

matrix::quaternion::quaternion(void) : h(1.0f), i(0.0f), j(0.0f), k(0.0f)
{
}

matrix::quaternion::quaternion(float data) : h(data), i(data), j(data), k(data)
{
}

matrix::quaternion::quaternion(float rotationX_degrees, float rotationY_degrees, float rotationZ_degrees)
{
	float	xRadian = deg_to_radians(rotationX_degrees) / 2.0f;
	float	yRadian = deg_to_radians(rotationY_degrees) / 2.0f;
	float	zRadian = deg_to_radians(rotationZ_degrees) / 2.0f;

	quaternion	tmpCos(0, std::cos(xRadian), std::cos(yRadian), std::cos(zRadian));
	quaternion	tmpSin(0, std::sin(xRadian), std::sin(yRadian), std::sin(zRadian));

	h = tmpCos.i * tmpCos.j * tmpCos.k + tmpSin.i * tmpSin.j * tmpSin.k;
	i = tmpSin.i * tmpCos.j * tmpCos.k - tmpCos.i * tmpSin.j * tmpSin.k;
	j = tmpCos.i * tmpSin.j * tmpCos.k + tmpSin.i * tmpCos.j * tmpSin.k;
	k = tmpCos.i * tmpCos.j * tmpSin.k - tmpSin.i * tmpSin.j * tmpCos.k; 
}

matrix::quaternion::quaternion(float h, float i, float j, float k) : h(h), i(i), j(j), k(k)
{
}

matrix::quaternion::quaternion(const quaternion& rhs) : h(rhs.h), i(rhs.i), j(rhs.j), k(rhs.k)
{
}

matrix::quaternion&	matrix::quaternion::operator=(const quaternion& rhs)
{
	h = rhs.h;
	i = rhs.i;
	j = rhs.j;
	k = rhs.k;

	return *this;
}

matrix::quaternion	matrix::quaternion::operator+(const quaternion& rhs) const
{
	quaternion	res = *this;

	res.h += rhs.h;
	res.i += rhs.i;
	res.j += rhs.j;
	res.k += rhs.k;

	return res;
}

matrix::quaternion&	matrix::quaternion::operator+=(const quaternion& rhs)
{
	*this = *this + rhs;

	return *this;
}

matrix::quaternion	matrix::quaternion::operator-(void) const
{
	quaternion	res;

	res.h = -(this->h);
	res.i = -(this->i);
	res.j = -(this->j);
	res.k = -(this->k);

	return res;
}

matrix::quaternion	matrix::quaternion::operator-(const quaternion& rhs) const
{
	quaternion	res = *this;

	res.h -= rhs.h;
	res.i -= rhs.i;
	res.j -= rhs.j;
	res.k -= rhs.k;

	return res;
}

matrix::quaternion&	matrix::quaternion::operator-=(const quaternion& rhs)
{
	*this = *this - rhs;

	return *this;
}

matrix::quaternion	matrix::quaternion::operator*(const quaternion& rhs) const
{
	float	tmpH = this->h * rhs.h	-	this->i * rhs.i	-	this->j * rhs.j	-	this->k * rhs.k;
	float	tmpI = this->h * rhs.i	+	this->i * rhs.h	+	this->j * rhs.k	-	this->k * rhs.j;
	float	tmpJ = this->h * rhs.j	-	this->i * rhs.k	+	this->j * rhs.h	+	this->k * rhs.i;
	float	tmpK = this->h * rhs.k	+	this->i * rhs.j	-	this->j * rhs.i	+	this->k * rhs.h;

	return quaternion(tmpH, tmpI, tmpJ, tmpK);
}

matrix::quaternion&	matrix::quaternion::operator*=(const quaternion& rhs)
{
	*this = *this * rhs;

	return *this;
}

matrix::quaternion	matrix::quaternion::operator*(float scalar) const
{
	quaternion	res = *this;

	res.h *= scalar;
	res.i *= scalar;
	res.j *= scalar;
	res.k *= scalar;

	return res;
}

matrix::quaternion&	matrix::quaternion::operator*=(float scalar)
{
	*this = *this * scalar;

	return *this;
}

matrix::quaternion	matrix::operator*(const float scalar, const quaternion& rhs)
{
	return rhs * scalar;
}

matrix::quaternion	matrix::quaternion::operator/(const quaternion& rhs) const
{
	return *this * matrix::inverse(rhs);
}

matrix::quaternion&	matrix::quaternion::operator/=(const quaternion& rhs)
{
	*this = *this / rhs;

	return *this;
}

bool	matrix::quaternion::operator==(const quaternion& rhs) const
{
	if (std::fabs(this->h - rhs.h) < 1e-6f && std::fabs(this->i - rhs.i) < 1e-6f && std::fabs(this->j - rhs.j) < 1e-6f && std::fabs(this->k - rhs.k) < 1e-6f)
		return false;
	else
		return true;
}

bool	matrix::quaternion::operator!=(const quaternion& rhs) const
{
	return !(*this == rhs);
}

void	matrix::quaternion::inverse(void)
{
	float		norm = this->norme();

	this->h =  this->h / norm;
	this->i = -this->i / norm;
	this->j = -this->j / norm;
	this->k = -this->k / norm;
}

void	matrix::quaternion::conjuge(void)
{
	this->i = -this->i;
	this->j = -this->j;
	this->k = -this->k;
}

float	matrix::quaternion::norme(void) const
{
	return std::sqrt(this->h * this->h + this->i * this->i + this->j * this->j + this->k * this->k);
}

void	matrix::quaternion::normalize(void)
{
	float		norm = this->norme();
	if (norm < 1e-6f)
	{
		h = 1.0f; i = 0.0f; j = 0.0f; k = 0.0f;
		return;
	}
	this->h = this->h / norm;
	this->i = this->i / norm;
	this->j = this->j / norm;
	this->k = this->k / norm;	
}

matrix::mat3	matrix::quaternion::toMat3(void) const
{
	mat3	res;

	res.data[0] = this->h * this->h + this->i * this->i - this->j * this->j - this->k * this->k;
	res.data[1] = 2 * (this->i * this->j + this->h * this->k);
	res.data[2] = 2 * (this->i * this->k - this->h * this->j);

	res.data[3] = 2 * (this->i * this->j - this->h * this->k);
	res.data[4] = this->h * this->h - this->i * this->i + this->j * this->j - this->k * this->k;
	res.data[5] = 2 * (this->j * this->k + this->h * this->i);

	res.data[6]  = 2 * (this->i * this->k + this->h * this->j);
	res.data[7]  = 2 * (this->j * this->k - this->h * this->i);
	res.data[8] = this->h * this->h - this->i * this->i - this->j * this->j + this->k * this->k;

	return res;
}

matrix::mat4	matrix::quaternion::toMat4(void) const
{
	mat4	res;

	res.data[0] = this->h * this->h + this->i * this->i - this->j * this->j - this->k * this->k;
	res.data[1] = 2 * (this->i * this->j + this->h * this->k);
	res.data[2] = 2 * (this->i * this->k - this->h * this->j);

	res.data[4] = 2 * (this->i * this->j - this->h * this->k);
	res.data[5] = this->h * this->h - this->i * this->i + this->j * this->j - this->k * this->k;
	res.data[6] = 2 * (this->j * this->k + this->h * this->i);

	res.data[8]  = 2 * (this->i * this->k + this->h * this->j);
	res.data[9]  = 2 * (this->j * this->k - this->h * this->i);
	res.data[10] = this->h * this->h - this->i * this->i - this->j * this->j + this->k * this->k;

	res.data[15] = 1.0f;

	return res;
}

std::ostream&	matrix::operator<<(std::ostream& os, const quaternion& rhs)
{
	os << rhs.h << " + " << rhs.i << "i + " << rhs.j << "j + " << rhs.k << "k";

	return os;
}

matrix::quaternion	matrix::inverse(const quaternion& quat)
{
	quaternion	res = quat;
	res.inverse();

	return res;
}

matrix::quaternion	matrix::conjuge(const quaternion& quat)
{
	quaternion	res = quat;
	res.conjuge();

	return res;
}

float	matrix::dot(const quaternion& lhs, const quaternion& rhs)
{
	return lhs.h * rhs.h + lhs.i * rhs.i + lhs.j * rhs.j + lhs.k * rhs.k;
}

float	matrix::norme(const quaternion& quat)
{
	return quat.norme();
}

matrix::quaternion	matrix::normalize(const quaternion& quat)
{
	quaternion	res = quat;
	res.normalize();

	return res;
}

#pragma once

#include "mat4.hpp"

#include <ostream>

/**
 * X  1  I  J  K
 * 1  1  i  j  k
 * I  i -1  k -j
 * J  j -k -1  i
 * K  k  j -i -1
 */
namespace matrix {
	struct quaternion {
		float	h;
		float	i;
		float	j;
		float	k;

		quaternion(void);
		quaternion(float data);
		quaternion(float rotationX_degrees, float rotationY_degrees, float rotationZ_degrees);
		quaternion(float h, float i, float j, float k);
		quaternion(const quaternion& rhs);
		quaternion&	operator=(const quaternion& rhs);

		quaternion			operator+(const quaternion& rhs) const;
		quaternion&			operator+=(const quaternion& rhs);
		quaternion			operator-(void) const;
		quaternion			operator-(const quaternion& rhs) const;
		quaternion&			operator-=(const quaternion& rhs);
		quaternion			operator*(const quaternion& rhs) const;
		quaternion&			operator*=(const quaternion& rhs);
		quaternion			operator*(float scalar) const;
		quaternion&			operator*=(float scalar);
		friend quaternion	operator*(const float scalar, const quaternion& rhs);
		quaternion			operator/(const quaternion& rhs) const;
		quaternion&			operator/=(const quaternion& rhs);

		bool	operator==(const quaternion& rhs) const;
		bool	operator!=(const quaternion& rhs) const;

		void	inverse(void);
		void	conjuge(void);
		float	norme(void) const;
		void	normalize(void);

		mat4	toMat4(void) const;
	};
	std::ostream&	operator<<(std::ostream& os, const quaternion& rhs);
	quaternion	operator*(const float scalar, const quaternion& rhs);

	quaternion	inverse(const quaternion& quat);
	quaternion	conjuge(const quaternion& quat);
	float		dot(const quaternion& a, const quaternion& b);
	float		norme(const quaternion& quat);
	quaternion	normalize(const quaternion& quat);
}

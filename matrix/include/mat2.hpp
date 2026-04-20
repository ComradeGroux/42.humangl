#pragma once

namespace matrix {
	struct mat2 {
		float	data[4];

		mat2(void);
		mat2(const mat2& rhs);
		mat2&	operator=(const mat2& rhs);
	};
}

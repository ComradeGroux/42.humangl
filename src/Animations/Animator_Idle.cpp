#include "Animator.hpp"

std::list<Animator::KeyFrame>	Animator::_createIdle(void)
{
	return {
		{
			.duration = 0.5f,
			.movement = {
				{
					BoneNode::body_part::HEAD,
					{
						.pos = {},
						.rotation = {},
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::CHEST,
					{
						.pos = {},
						.rotation = {},
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::UPPER_ARM_LEFT,
					{
						.pos = {},
						.rotation = {},
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::LOWER_ARM_LEFT,
					{
						.pos = {},
						.rotation = {},
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::UPPER_ARM_RIGHT,
					{
						.pos = {},
						.rotation = {},
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::LOWER_ARM_RIGHT,
					{
						.pos = {},
						.rotation = {},
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::UPPER_LEG_LEFT,
					{
						.pos = {},
						.rotation = {},
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::LOWER_LEG_LEFT,
					{
						.pos = {},
						.rotation = {},
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::UPPER_LEG_RIGHT,
					{
						.pos = {},
						.rotation = {},
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::LOWER_LEG_RIGHT,
					{
						.pos = {},
						.rotation = {},
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				}
			}
		},
		{
			.duration = 0.5f,
			.movement = {
				{
					BoneNode::body_part::HEAD,
					{
						.pos = {},
						.rotation = { 1.0f, 0.0f, -0.025f, 0.0f },
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::CHEST,
					{
						.pos = { 0.0f, -0.1f, 0.0f },
						.rotation = {},
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::UPPER_ARM_LEFT,
					{
						.pos = {},
						.rotation = { 1.0f, 0.025f, 0.0f, 0.0f },
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::LOWER_ARM_LEFT,
					{
						.pos = {},
						.rotation = {},
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::UPPER_ARM_RIGHT,
					{
						.pos = {},
						.rotation = { 1.0f, -0.025f, 0.0f, 0.0f },
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::LOWER_ARM_RIGHT,
					{
						.pos = {},
						.rotation = {},
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::UPPER_LEG_LEFT,
					{
						.pos = {},
						.rotation = { 1.0f, 0.0f, 0.0f, -0.05f },
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::LOWER_LEG_LEFT,
					{
						.pos = {},
						.rotation = { 1.0f, 0.0f, 0.0f, 0.1f },
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::UPPER_LEG_RIGHT,
					{
						.pos = {},
						.rotation = { 1.0f, 0.0f, 0.0f, -0.05f },
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::LOWER_LEG_RIGHT,
					{
						.pos = {},
						.rotation = { 1.0f, 0.0f, 0.0f, 0.1f },
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				}
			}
		},
		{
			.duration = 0.5f,
			.movement = {
				{
					BoneNode::body_part::HEAD,
					{
						.pos = {},
						.rotation = { 1.0f, 0.0f, 0.0f, 0.0f },
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::CHEST,
					{
						.pos = {},
						.rotation = {},
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::UPPER_ARM_LEFT,
					{
						.pos = {},
						.rotation = {},
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::LOWER_ARM_LEFT,
					{
						.pos = {},
						.rotation = {},
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::UPPER_ARM_RIGHT,
					{
						.pos = {},
						.rotation = {},
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::LOWER_ARM_RIGHT,
					{
						.pos = {},
						.rotation = {},
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::UPPER_LEG_LEFT,
					{
						.pos = {},
						.rotation = {},
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::LOWER_LEG_LEFT,
					{
						.pos = {},
						.rotation = {},
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::UPPER_LEG_RIGHT,
					{
						.pos = {},
						.rotation = {},
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::LOWER_LEG_RIGHT,
					{
						.pos = {},
						.rotation = {},
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				}
			}
		},
		{
			.duration = 0.5f,
			.movement = {
				{
					BoneNode::body_part::HEAD,
					{
						.pos = {},
						.rotation = { 1.0f, 0.0f, 0.025f, 0.0f },
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::CHEST,
					{
						.pos = { 0.0f, -0.05f, 0.0f },
						.rotation = {},
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::UPPER_ARM_LEFT,
					{
						.pos = {},
						.rotation = { 1.0f, 0.025f, 0.0f, 0.0f },
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::LOWER_ARM_LEFT,
					{
						.pos = {},
						.rotation = {},
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::UPPER_ARM_RIGHT,
					{
						.pos = {},
						.rotation = { 1.0f, -0.025f, 0.0f, 0.0f },
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::LOWER_ARM_RIGHT,
					{
						.pos = {},
						.rotation = {},
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::UPPER_LEG_LEFT,
					{
						.pos = {},
						.rotation = { 1.0f, 0.0f, 0.0f, -0.05f },
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::LOWER_LEG_LEFT,
					{
						.pos = {},
						.rotation = { 1.0f, 0.0f, 0.0f, 0.1f },
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::UPPER_LEG_RIGHT,
					{
						.pos = {},
						.rotation = { 1.0f, 0.0f, 0.0f, -0.05f },
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::LOWER_LEG_RIGHT,
					{
						.pos = {},
						.rotation = { 1.0f, 0.0f, 0.0f, 0.1f },
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				}
			}
		}
	};
}

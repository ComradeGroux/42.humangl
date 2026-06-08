#include "Animator.hpp"

std::list<Animator::KeyFrame>	Animator::_createJump(void)
{
	return {
		{	// Standing up
			.duration = 0.3f,
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
		{	// Flexing the kneels
			.duration = 0.3f,
			.movement = {
				{
					BoneNode::body_part::HEAD,
					{
						.pos = { 0.1f, -0.1f, 0.0f },
						.rotation = { 1.0f, 0.0f, 0.0f, -0.2f },
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::CHEST,
					{
						.pos = { 0.0f, -0.1f, 0.0f },
						.rotation = { 1.0f, 0.0f, 0.0f, 0.15f },
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::UPPER_ARM_LEFT,
					{
						.pos = {},
						.rotation = { 1.0f, 0.1f, 0.0f, 0.3f },
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::LOWER_ARM_LEFT,
					{
						.pos = { -0.2f, 0.0f, 0.0f },
						.rotation = { 1.0f, 0.0f, 0.0f, -0.4f },
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::UPPER_ARM_RIGHT,
					{
						.pos = {},
						.rotation = { 1.0f, -0.1f, 0.0f, 0.3f },
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::LOWER_ARM_RIGHT,
					{
						.pos = { -0.2f, 0.0f, 0.0f },
						.rotation = { 1.0f, 0.0f, 0.0f, -0.4f },
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::UPPER_LEG_LEFT,
					{
						.pos = { -0.15f, 0.1f, 0.0f },
						.rotation = { 1.0f, 0.0f, 0.0f, -0.3f },
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::LOWER_LEG_LEFT,
					{
						.pos = { 0.1f, 0.0f, 0.0f },
						.rotation = { 1.0f, 0.0f, 0.0f, 0.3f },
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::UPPER_LEG_RIGHT,
					{
						.pos = { -0.15f, 0.1f, 0.0f },
						.rotation = { 1.0f, 0.0f, 0.0f, -0.3f },
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::LOWER_LEG_RIGHT,
					{
						.pos = { 0.0f, 0.0f, 0.0f },
						.rotation = { 1.0f, 0.0f, 0.0f, 0.2f },
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				}
			}
		},
		{	// Putting the arms up
			.duration = 0.2f,
			.movement = {
				{
					BoneNode::body_part::HEAD,
					{
						.pos = { 0.1f, -0.1f, 0.0f },
						.rotation = { 1.0f, 0.0f, 0.0f, -0.2f },
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::CHEST,
					{
						.pos = { 0.0f, 0.0f, 0.0f },
						.rotation = { 1.0f, 0.0f, 0.0f, 0.15f },
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::UPPER_ARM_LEFT,
					{
						.pos = {},
						.rotation = { 1.0f, 0.1f, 0.0f, 0.0f },
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::LOWER_ARM_LEFT,
					{
						.pos = { -0.2f, 0.0f, 0.0f },
						.rotation = { 1.0f, 0.0f, 0.0f, -0.4f },
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::UPPER_ARM_RIGHT,
					{
						.pos = {},
						.rotation = { 1.0f, -0.1f, 0.0f, 0.0f },
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::LOWER_ARM_RIGHT,
					{
						.pos = { -0.2f, 0.0f, 0.0f },
						.rotation = { 1.0f, 0.0f, 0.0f, -0.4f },
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::UPPER_LEG_LEFT,
					{
						.pos = { -0.15f, 0.1f, 0.0f },
						.rotation = { 1.0f, 0.0f, 0.0f, -0.3f },
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::LOWER_LEG_LEFT,
					{
						.pos = { 0.1f, 0.0f, 0.0f },
						.rotation = { 1.0f, 0.0f, 0.0f, 0.3f },
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::UPPER_LEG_RIGHT,
					{
						.pos = { -0.15f, 0.1f, 0.0f },
						.rotation = { 1.0f, 0.0f, 0.0f, -0.3f },
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::LOWER_LEG_RIGHT,
					{
						.pos = { 0.0f, 0.0f, 0.0f },
						.rotation = { 1.0f, 0.0f, 0.0f, 0.2f },
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				}
			}
		},
		{	// Extending the legs
			.duration = 0.4f,
			.movement = {
				{
					BoneNode::body_part::HEAD,
					{
						.pos = { 0.1f, -0.1f, 0.0f },
						.rotation = { 1.0f, 0.0f, 0.0f, -0.2f },
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::CHEST,
					{
						.pos = { 0.0f, 0.0f, 0.0f },
						.rotation = { 1.0f, 0.0f, 0.0f, 0.0f },
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::UPPER_ARM_LEFT,
					{
						.pos = {},
						.rotation = { 1.0f, 0.1f, 0.0f, -0.4f },
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::LOWER_ARM_LEFT,
					{
						.pos = { -0.2f, 0.0f, 0.0f },
						.rotation = { 1.0f, 0.0f, 0.0f, -0.4f },
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::UPPER_ARM_RIGHT,
					{
						.pos = {},
						.rotation = { 1.0f, -0.1f, 0.0f, -0.4f },
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::LOWER_ARM_RIGHT,
					{
						.pos = { -0.2f, 0.0f, 0.0f },
						.rotation = { 1.0f, 0.0f, 0.0f, -0.4f },
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
		{	// Actually jumping
			.duration = 0.4f,
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
						.pos = { 0.0f, 1.0f, 0.0f },
						.rotation = {},
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::UPPER_ARM_LEFT,
					{
						.pos = {},
						.rotation = { 1.0f, 0.0f, 0.0f, -0.8f },
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::LOWER_ARM_LEFT,
					{
						.pos = { -0.2f, 0.1f, 0.0f },
						.rotation = { 1.0f, 0.0f, 0.0f, -0.8f },
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::UPPER_ARM_RIGHT,
					{
						.pos = {},
						.rotation = { 1.0f, 0.0f, 0.0f, -0.8f },
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::LOWER_ARM_RIGHT,
					{
						.pos = { -0.2f, 0.1f, 0.0f },
						.rotation = { 1.0f, 0.0f, 0.0f, -0.8f },
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
		}
	};
}
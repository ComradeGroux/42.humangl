#include "Animator.hpp"

std::list<Animator::KeyFrame>	Animator::_createIdle(void)
{
	return {
		{
			.duration = 1.0f,
			.movement = {
				{
					BoneNode::body_part::HEAD,
					{
						.pos = { 0.0f, 0.0f, 0.0f },
						.rotation = { 1.0f, 0.0f, 0.0f, 0.0f },
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::CHEST,
					{
						.pos = { 0.0f, 0.5f, 0.0f },
						.rotation = { 1.0f, 0.0f, 0.0f, 0.0f },
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::UPPER_ARM_LEFT,
					{
						.pos = { 0.0f, 0.0f, 0.0f },
						.rotation = { 1.0f, 0.0f, 0.0f, 0.0f },
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::LOWER_ARM_LEFT,
					{
						.pos = { 0.0f, 0.0f, 0.0f },
						.rotation = { 1.0f, 0.0f, 0.0f, 0.0f },
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::UPPER_ARM_RIGHT,
					{
						.pos = { 0.0f, 0.0f, 0.0f },
						.rotation = { 1.0f, 0.0f, 0.0f, 0.0f },
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::LOWER_ARM_RIGHT,
					{
						.pos = { 0.0f, 0.0f, 0.0f },
						.rotation = { 1.0f, 0.0f, 0.0f, 0.0f },
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::UPPER_LEG_LEFT,
					{
						.pos = { 0.0f, 0.0f, 0.0f },
						.rotation = { 1.0f, 0.0f, 0.0f, 0.0f },
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::LOWER_LEG_LEFT,
					{
						.pos = { 0.0f, 0.0f, 0.0f },
						.rotation = { 1.0f, 0.0f, 0.0f, 0.0f },
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::UPPER_LEG_RIGHT,
					{
						.pos = { 0.0f, 0.0f, 0.0f },
						.rotation = { 1.0f, 0.0f, 0.0f, 0.0f },
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::LOWER_LEG_RIGHT,
					{
						.pos = { 0.0f, 0.0f, 0.0f },
						.rotation = { 1.0f, 0.0f, 0.0f, 0.0f },
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				}
			}
		},
		{
			.duration = 1.0f,
			.movement = {
				{
					BoneNode::body_part::HEAD,
					{
						.pos = { 0.0f, 0.0f, 0.0f },
						.rotation = { 1.0f, 0.0f, 0.0f, 0.0f },
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
						.pos = { 0.0f, 0.0f, 0.0f },
						.rotation = { 1.0f, 0.0f, 0.0f, 0.0f },
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::LOWER_ARM_LEFT,
					{
						.pos = { 0.0f, 0.0f, 0.0f },
						.rotation = { 1.0f, 0.0f, 0.0f, 0.0f },
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::UPPER_ARM_RIGHT,
					{
						.pos = { 0.0f, 0.0f, 0.0f },
						.rotation = { 1.0f, 0.0f, 0.0f, 0.0f },
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::LOWER_ARM_RIGHT,
					{
						.pos = { 0.0f, 0.0f, 0.0f },
						.rotation = { 1.0f, 0.0f, 0.0f, 0.0f },
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::UPPER_LEG_LEFT,
					{
						.pos = { 0.0f, 0.0f, 0.0f },
						.rotation = { 1.0f, 0.0f, 0.0f, 0.0f },
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::LOWER_LEG_LEFT,
					{
						.pos = { 0.0f, 0.0f, 0.0f },
						.rotation = { 1.0f, 0.0f, 0.0f, 0.0f },
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::UPPER_LEG_RIGHT,
					{
						.pos = { 0.0f, 0.0f, 0.0f },
						.rotation = { 1.0f, 0.0f, 0.0f, 0.0f },
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				},
				{
					BoneNode::body_part::LOWER_LEG_RIGHT,
					{
						.pos = { 0.0f, 0.0f, 0.0f },
						.rotation = { 1.0f, 0.0f, 0.0f, 0.0f },
						.scaling = { 1.0f, 1.0f, 1.0f }
					}
				}
			}
		},
	};
}

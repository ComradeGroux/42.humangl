#include "Animator.hpp"

std::list<Animator::KeyFrame>	Animator::_createWalk(void)
{
	return {
		{
			.duration = 20.0f,
			.movement = {
				{
					BoneNode::body_part::HEAD,
					{
						.pos = {},
						.rotation = {},
						.scaling = {}
					}
				},
				{
					BoneNode::body_part::CHEST,
					{
						.pos = {},
						.rotation = {},
						.scaling = {}
					}
				},
				{
					BoneNode::body_part::UPPER_ARM_LEFT,
					{
						.pos = {},
						.rotation = {},
						.scaling = {}
					}
				},
				{
					BoneNode::body_part::LOWER_ARM_LEFT,
					{
						.pos = {},
						.rotation = {},
						.scaling = {}
					}
				},
				{
					BoneNode::body_part::UPPER_ARM_RIGHT,
					{
						.pos = {},
						.rotation = {},
						.scaling = {}
					}
				},
				{
					BoneNode::body_part::LOWER_ARM_RIGHT,
					{
						.pos = {},
						.rotation = {},
						.scaling = {}
					}
				},
				{
					BoneNode::body_part::UPPER_LEG_LEFT,
					{
						.pos = {},
						.rotation = {},
						.scaling = {}
					}
				},
				{
					BoneNode::body_part::LOWER_LEG_LEFT,
					{
						.pos = {},
						.rotation = {},
						.scaling = {}
					}
				},
				{
					BoneNode::body_part::UPPER_LEG_RIGHT,
					{
						.pos = {},
						.rotation = {},
						.scaling = {}
					}
				},
				{
					BoneNode::body_part::LOWER_LEG_RIGHT,
					{
						.pos = {},
						.rotation = {},
						.scaling = {}
					}
				}
			}
		},
	};
}
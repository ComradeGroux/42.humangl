#pragma once

#include "MatrixStack.hpp"

#include <map>
#include <functional>

class BoneNode {
	public:
		enum body_part {
			NOTHING,
			HEAD,
			CHEST,
			UPPER_ARM_LEFT,
			UPPER_ARM_RIGHT,
			LOWER_ARM_LEFT,
			LOWER_ARM_RIGHT,
			UPPER_LEG_LEFT,
			UPPER_LEG_RIGHT,
			LOWER_LEG_LEFT,
			LOWER_LEG_RIGHT
		};

	private:
		matrix::mat4								_localTransform;
		std::map<body_part, BoneNode *>				_children;
		std::function<void (const matrix::mat4&)>	_drawFunc;

		void	_render(MatrixStack& stack);

	public:
		matrix::mat4	animatedTransform;

		BoneNode(std::function<void (const matrix::mat4&)> f);
		BoneNode(std::function<void (const matrix::mat4&)> f, matrix::mat4 transform);
		~BoneNode(void);

		void	addChild(body_part name, BoneNode* child);
		void	clearAndFreeChildren(void);

		void	render(void);

		BoneNode*	getBone(body_part bone);
};

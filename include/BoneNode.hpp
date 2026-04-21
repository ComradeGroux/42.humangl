#pragma once

#include "matrix.hpp"
#include "MatrixStack.hpp"

#include <vector>
#include <functional>

class BoneNode {
	private:
		std::vector<BoneNode *>						_children;
		std::function<void (const matrix::mat4&)>	_drawFunc;
		
		void	_render(MatrixStack& stack);
	
	public:
		matrix::mat4	localTransform;

		BoneNode(std::function<void (const matrix::mat4&)> f);
		~BoneNode(void);

		void	addChild(BoneNode* child);
		void	clearAndFreeChildren(void);

		void	render(void);
};

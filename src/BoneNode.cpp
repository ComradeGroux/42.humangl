#include "BoneNode.hpp"

BoneNode::BoneNode(std::function<void (const matrix::mat4&)> f) : _drawFunc(f)
{
}

BoneNode::~BoneNode(void)
{
	clearAndFreeChildren();
}

void	BoneNode::addChild(BoneNode* child)
{
	_children.push_back(child);
}

void	BoneNode::clearAndFreeChildren(void)
{
	for (BoneNode* child : _children)
		delete child;
	_children.clear();
}

void	BoneNode::render(void)
{
	MatrixStack	stack;
	_render(stack);
}

void	BoneNode::_render(MatrixStack& stack)
{
	stack.push();
	stack.apply(localTransform);

	_drawFunc(stack.top());

	for (BoneNode *child : _children)
		child->_render(stack);

	stack.pop();
}

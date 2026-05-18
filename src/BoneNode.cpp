#include "BoneNode.hpp"

BoneNode::BoneNode(std::function<void (const matrix::mat4&)> f) : _drawFunc(f)
{
}

BoneNode::BoneNode(std::function<void (const matrix::mat4&)> f, matrix::mat4 transform) : _drawFunc(f), localTransform(transform)
{
}

BoneNode::~BoneNode(void)
{
	clearAndFreeChildren();
}

void	BoneNode::addChild(body_part name, BoneNode* child)
{
	_children[name] = child;
}

void	BoneNode::clearAndFreeChildren(void)
{
	for (std::pair<body_part, BoneNode *> child : _children)
		delete child.second;
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

	for (std::pair<body_part, BoneNode *> child : _children)
		child.second->_render(stack);

	stack.pop();
}

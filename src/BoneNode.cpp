#include "BoneNode.hpp"

BoneNode::BoneNode(std::function<void (const matrix::mat4&)> f) : _drawFunc(f)
{
	matrix::mat4	transform;
	matrix::identity(transform);
	_localTransform = transform;
}

BoneNode::BoneNode(std::function<void (const matrix::mat4&)> f, matrix::mat4 transform) : _localTransform(transform), _drawFunc(f)
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
	stack.apply(_localTransform * animatedTransform);

	if (_drawFunc)
		_drawFunc(stack.top());

	for (std::pair<body_part, BoneNode *> child : _children)
		child.second->_render(stack);

	stack.pop();
}

BoneNode*	BoneNode::getBone(body_part bone)
{
	std::map<body_part, BoneNode*>::iterator	it = _children.find(bone);

	if (it != _children.end())
		return _children[bone];

	BoneNode	*curr;
	for (std::pair<body_part, BoneNode *> child: _children)
	{
		curr = child.second->getBone(bone);
		if (curr != nullptr)
			return curr;
	}
	return nullptr;
}

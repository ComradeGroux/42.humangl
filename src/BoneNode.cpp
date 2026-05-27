#include "BoneNode.hpp"

BoneNode::BoneNode(std::function<void (const matrix::mat4&)> f) : _drawFunc(f)
{
	matrix::identity(_localTransform);
	_scale = matrix::vec3(1.0f, 1.0f, 1.0f);
	matrix::identity(animatedTransform);
}

BoneNode::BoneNode(std::function<void (const matrix::mat4&)> f, matrix::mat4 transform)
{
	_drawFunc = f;
	_scale = matrix::vec3(transform.data[0], transform.data[5], transform.data[10]);
	transform.data[0] = 1.0f;
	transform.data[5] = 1.0f;
	transform.data[10] = 1.0f;
	_localTransform = transform;
	matrix::identity(animatedTransform);
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
		_drawFunc(matrix::scale(stack.top(), _scale));

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

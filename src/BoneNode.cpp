#include "BoneNode.hpp"

BoneNode::BoneNode(std::function<void (const matrix::mat4&)> f) : _drawFunc(f)
{
	matrix::identity(_localTransform);
	_scale = matrix::vec3(1.0f, 1.0f, 1.0f);
	matrix::identity(animatedTransform);
}

BoneNode::BoneNode(std::function<void (const matrix::mat4&)> f, const matrix::mat4& transform, const matrix::vec3& scale)
{
	_drawFunc = f;
	_scale = scale;
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
	_render(stack, { 1.0f, 1.0f, 1.0f });
}

void	BoneNode::_render(MatrixStack& stack, const matrix::vec3& parentScale)
{
	stack.push();

	matrix::mat4 adjustedTransform = _localTransform;
	adjustedTransform.data[12] *= parentScale.x;
	adjustedTransform.data[13] *= parentScale.y;
	adjustedTransform.data[14] *= parentScale.z;

	stack.apply(adjustedTransform * animatedTransform);

	if (_drawFunc)
		_drawFunc(matrix::scale(stack.top(), _scale));

	for (std::pair<body_part, BoneNode *> child : _children)
		child.second->_render(stack, _scale);

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

matrix::vec3	BoneNode::getScale(void) const
{
	return _scale;
}

#include "Animator.hpp"
#include "lerp.hpp"

Animator::Animator(void)
{
	_createAnimations();
	chooseAnimation(ANIM_IDLE);
}

Animator::Animator(BoneNode* model): _model(model)
{
	if (_model == nullptr)
		throw std::runtime_error("Failed to allocate the character");

	_createAnimations();
	chooseAnimation(ANIM_IDLE);
}

Animator::~Animator(void)
{
	if (_model != nullptr)
		delete _model;
}

void	Animator::_createAnimations(void)
{
	_animationsFrames[ANIM_IDLE] = _createIdle();
	_animationsFrames[ANIM_WALK] = _createWalk();
	_animationsFrames[ANIM_JUMP] = _createJump();
}

void	Animator::loadModel(BoneNode* model)
{
	if (model == nullptr)
		throw std::runtime_error("The provided model is NULL");

	_model = model;
}

void	Animator::chooseAnimation(AnimationType animation)
{
	_animation = animation;
	_currKeyframe = _animationsFrames[_animation].begin();
	_timeInKeyframe = 0.0f;
}

Animator::AnimationType	Animator::getActualAnimation(void) const
{
	return _animation;
}

void	Animator::renderAnimation(double deltaTime)
{
	if (!_model)
		throw std::runtime_error("You should provide a model before trying to animate something !");

	_timeInKeyframe += deltaTime;
	if (_timeInKeyframe >= _currKeyframe->duration)
	{
		_timeInKeyframe -= _currKeyframe->duration;
		if (++_currKeyframe == _animationsFrames[_animation].end())
		{
			_currKeyframe = _animationsFrames[_animation].begin();
			_timeInKeyframe = 0.0f;
		}
	}

	std::list<KeyFrame>::iterator	prevFrame = _currKeyframe;
	if (prevFrame == _animationsFrames[_animation].begin())
		prevFrame = std::prev(_animationsFrames[_animation].end());
	else
		--prevFrame;

	double				t = _timeInKeyframe / _currKeyframe->duration;
	matrix::vec3		pos;
	matrix::vec3		scale;
	matrix::quaternion	rot;
	for (std::pair<BoneNode::body_part, AnimNode> curr : _currKeyframe->movement)
	{
		pos = matrix::lerp(prevFrame->movement[curr.first].pos, curr.second.pos, t);
		scale = matrix::lerp(prevFrame->movement[curr.first].scaling, curr.second.scaling, t);
		rot = matrix::slerp(prevFrame->movement[curr.first].rotation, curr.second.rotation, t);

		BoneNode*	currBone = _model->getBone(curr.first);
		if (currBone == nullptr)
			throw std::runtime_error("Bone does not exist !");

		currBone->animatedTransform = matrix::compose(pos, rot, scale, currBone->getPivot() * currBone->getScale());
	}

	_model->render();
}

void	Animator::renderAnimation(BoneNode* model, AnimationType animation, double deltaTime)
{
	_model = model;
	chooseAnimation(animation);
	renderAnimation(deltaTime);
}

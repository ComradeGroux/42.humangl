#include "Animator.hpp"
#include "lerp.hpp"

Animator::Animator(void)
{
	_createAnimations();
	chooseAnimation(ANIM_IDLE);
}

Animator::Animator(BoneNode* model): _model(model)
{
	_createAnimations();
	chooseAnimation(ANIM_IDLE);
}

void	Animator::_createAnimations(void)
{
	_animationsFrames[ANIM_IDLE] = _createIdle();
	_animationsFrames[ANIM_WALK] = _createWalk();
	_animationsFrames[ANIM_JUMP] = _createJump();
}

void	Animator::loadModel(BoneNode* model)
{
	_model = model;
}

void	Animator::chooseAnimation(AnimationType animation)
{
	_animation = animation;
	_currKeyframe = _animationsFrames[_animation].begin();
	_timeInKeyframe = 0.0f;
}

void	Animator::renderAnimation(double deltaTime)
{
	if (!_model)
		throw std::runtime_error("You should provide a model before trying to animate something !");

	_timeInKeyframe += deltaTime;
	if (_timeInKeyframe >= (*_currKeyframe).duration)
	{
		_currKeyframe++;
		if (_currKeyframe == _animationsFrames[_animation].end())
		_currKeyframe = _animationsFrames[_animation].begin();
		_timeInKeyframe -= (*_currKeyframe).duration;
	}

	matrix::vec3		pos;
	matrix::vec3		scale;
	matrix::quaternion	rot;
	double				t = _timeInKeyframe / (*_currKeyframe).duration;
	for (std::pair<BoneNode::body_part, AnimNode> curr : (*_currKeyframe).movement)
	{
		std::list<KeyFrame>::iterator	nextFrame = _currKeyframe;
		if (++nextFrame == _animationsFrames[_animation].end())
			nextFrame = _animationsFrames[_animation].begin();

		pos = matrix::lerp(curr.second.pos, (*nextFrame).movement[curr.first].pos, t);
		scale = matrix::lerp(curr.second.scaling, (*nextFrame).movement[curr.first].scaling, t);
		rot = matrix::slerp(curr.second.rotation, (*nextFrame).movement[curr.first].rotation, t);

		BoneNode*	currBone = _model->getBone(curr.first);
		if (currBone == nullptr)
			throw std::runtime_error("Bone does not exist !");

		currBone->animatedTransform = matrix::compose(pos, rot, scale);
	}

	_model->render();
}

void	Animator::renderAnimation(BoneNode* model, AnimationType animation, double deltaTime)
{
	_model = model;
	chooseAnimation(animation);
	renderAnimation(deltaTime);
}

#include "Animator.hpp"

Animator::Animator(BoneNode* model): _model(model)
{
	_createAnimations();
}

void	Animator::_createAnimations(void)
{
	_animationsFrames[ANIM_IDLE] = _createIdle();
	_animationsFrames[ANIM_WALK] = _createWalk();
	_animationsFrames[ANIM_JUMP] = _createJump();
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
			chooseAnimation(_animation);
	}

	/**
	 * TODO -> RENDER ANIMATION
	 */
}

void	Animator::renderAnimation(BoneNode* model, AnimationType animation, double deltaTime)
{
	_model = model;
	chooseAnimation(animation);
	renderAnimation(deltaTime);
}

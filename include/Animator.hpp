#pragma once

#include "BoneNode.hpp"

#include <map>
#include <list>

#include "vec3.hpp"
#include "quaternion.hpp"

struct AnimNode {
	matrix::vec3		pos;
	matrix::quaternion	rotation;
	matrix::vec3		scaling;
};

class Animator {
	public:
		enum AnimationType {
			ANIM_TPOSE,
			ANIM_IDLE,
			ANIM_WALK,
			ANIM_JUMP
		};
		struct KeyFrame {
			double									duration;
			std::map<BoneNode::body_part, AnimNode>	movement;
		};

	private:
		BoneNode*										_model = nullptr;
		AnimationType									_animation;
		std::map<AnimationType, std::list<KeyFrame>>	_animationsFrames;

		std::list<KeyFrame>::iterator	_currKeyframe;
		double							_timeInKeyframe;

		void				_createAnimations(void);
		std::list<KeyFrame>	_createTPose(void);
		std::list<KeyFrame>	_createIdle(void);
		std::list<KeyFrame>	_createWalk(void);
		std::list<KeyFrame>	_createJump(void);

	public:
		Animator(void);
		Animator(BoneNode* model);

		void			loadModel(BoneNode* model);
		void			chooseAnimation(AnimationType animation);
		AnimationType	getActualAnimation(void) const;
		void			renderAnimation(double deltaTime);
		void			renderAnimation(BoneNode* model, AnimationType animation, double deltaTime);
};

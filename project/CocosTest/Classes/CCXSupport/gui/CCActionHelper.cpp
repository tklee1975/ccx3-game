//
//  CCActionHelper.cpp
//  Dg
//
//  Created by Ken Lee on 23/1/14.
//
//

#include "CCActionHelper.h"


FiniteTimeAction *CCActionHelper::createMoveIn(Node *node, float moveInTime,
													  const std::function<void()> &func)
{
	
	// Modify the node
	Point endPos = node->getPosition();
	Point startPos = Point(endPos);
	startPos.y = -10;
	node->setPosition(startPos);
	
	Vector<FiniteTimeAction *> array;
	
	array.pushBack(Show::create());
	
	// Animation
	MoveTo *moveTo = MoveTo::create(moveInTime, endPos);
	EaseBackOut *easeMove = EaseBackOut::create(moveTo);
	array.pushBack(easeMove);
	
	if(func) {
		CallFunc *call = CallFunc::create(func);
		array.pushBack(call);
	}
	
	Sequence *seq = Sequence::create(array);
	
	return seq;
}

FiniteTimeAction *CCActionHelper::createMoveInAndFade(Node *node,
													  float moveInTime, float delayTime, float fadeTime,
													  bool autoRemove,
													  const std::function<void()> &func)
{
	
	// Modify the node
	Point endPos = node->getPosition();
	Point startPos = Point(endPos);
	startPos.y = -10;
	node->setPosition(startPos);
	
	Vector<FiniteTimeAction *> array;
	
	array.pushBack(Show::create());
	
	// Animation
	MoveTo *moveTo = MoveTo::create(moveInTime, endPos);
	EaseIn *easeMove = EaseIn::create(moveTo, 0.1f);
	array.pushBack(easeMove);
	
	DelayTime *delay = DelayTime::create(delayTime);
	array.pushBack(delay);
	
	FadeOut *fadeOut = FadeOut::create(fadeTime);
	EaseOut *easeFade = EaseOut::create(fadeOut, 0.3f);
	array.pushBack(easeFade);
	
	if(autoRemove) {
		array.pushBack(RemoveSelf::create());
	}
	
	if(func) {
		CallFunc *call = CallFunc::create(func);
		array.pushBack(call);
	}
	
	Sequence *seq = Sequence::create(array);
	
	return seq;	
}


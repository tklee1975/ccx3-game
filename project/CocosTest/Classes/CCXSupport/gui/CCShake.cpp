//
//  CCShake.cpp
//  Dg
//
//  Created by Ken Lee on 1/2/14.
//
//

#include "CCShake.h"
#include <stdlib.h>

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#define RANDOM_0_1()	((float) std::rand() / RAND_MAX)
#else
#define RANDOM_0_1()	((float) arc4random() / 0x100000000)
#endif

Shake::Shake()
: mInitialPos(0, 0)
, mStrengthX(0)
, mStrengthY(0)
, mNumShake(0)
, mShakeCoolDown(0)
, mShakeTimer(0)
, mLastTime(0)
{
	
}

Shake::~Shake()
{
	
}

Shake *Shake::create(float duration, float strength, int numShake)
{
	return create(duration, strength, strength, numShake);
}

Shake *Shake::create(float duration, float strengthX, float strengthY, int numShake)
{
	Shake *action = new Shake();
	action->initWithDuration(duration, strengthX, strengthY, numShake);
	action->autorelease();
	
	return action;
}

bool Shake::initWithDuration(float duration, float strengthX, float strengthY, int numShake)
{
	if (ActionInterval::initWithDuration(duration))
	{
		mStrengthX = strengthX;
		mStrengthY = strengthY;
		mNumShake = numShake;
		
		mShakeCoolDown = mNumShake <= 0 ? 0 : duration / mNumShake;
		mShakeTimer = mShakeCoolDown;
		
		return true;
	}
	
	return false;
}

float Shake::getRandOffset(int min, int max)
{
	return RANDOM_0_1() * (max - min) + min;
}


void Shake::update(float time)
{
	// note: time is the percent of the duration .
	// Find the delta time and save the last time value
	float delta = (time - mLastTime) * getDuration();
	mLastTime = time;
	
	//log("shake: time=%f mLastTime=%f delta=%f", time, mLastTime, delta);
	// handle the cooldown
	if(mShakeTimer > 0) {
		mShakeTimer = mShakeTimer - delta;
		return;
	}
	
	
	float x = mInitialPos.x + getRandOffset(-mStrengthX, mStrengthX);
	float y = mInitialPos.y + getRandOffset(-mStrengthY, mStrengthY);
	// log("shake: update: %f,%f", x, y);
	
	// move the target to a shaked position
	_target->setPosition(x, y);
	
	//log("shake: mShakeTimer=%f mShakeCoolDown=%f delta=%f", mShakeTimer, mShakeCoolDown, time);
	
	// Reset the timer
	mShakeTimer = mShakeCoolDown;
}

void Shake::startWithTarget(Node *pTarget)
{
	ActionInterval::startWithTarget(pTarget);
	
	// save the initial position
	mInitialPos = pTarget->getPosition();
	mShakeTimer = 0;
	mLastTime = 0;
}

void Shake::stop(void)
{
	// Action is done, reset clip position
	_target->setPosition(mInitialPos.x, mInitialPos.y);
	
	CCActionInterval::stop();
}

Shake *Shake::reverse(void) const
{
	return Shake::create(getDuration(), mStrengthY, mStrengthX);
}

Shake *Shake::clone() const
{
	return Shake::create(getDuration(), mStrengthY, mStrengthX);
}
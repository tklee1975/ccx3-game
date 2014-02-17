//
//  CCShake.h
//  Dg
//
//  Created by Ken Lee on 1/2/14.
//
//

#ifndef __Dg__CCShake__
#define __Dg__CCShake__

#include <iostream>


#include "cocos2d.h"

USING_NS_CC;

NS_CC_BEGIN

class Shake : public ActionInterval
{
public:
	Shake();
	virtual ~Shake();
	
	static Shake* create(float duration, float strength, int numShake);
	static Shake* create(float duration, float strengthX, float strengthY, int numShake);
	bool initWithDuration(float duration, float strengthX, float strengthY, int numShake);
	
	virtual void startWithTarget(Node *pTarget) override;
	virtual void update(float time) override;
	virtual void stop(void);
	
	virtual Shake *clone() const override;
	virtual Shake *reverse(void) const override;
	
protected:
	// Initial position of the shaked node
	Point mInitialPos;
	
	// Strength of the action
	float mStrengthX;
	float mStrengthY;
	int mNumShake;
	float mShakeCoolDown;
	float mShakeTimer;
	float mLastTime;

private:
	float getRandOffset(int min, int max);
};

NS_CC_END

#endif /* defined(__Dg__CCShake__) */

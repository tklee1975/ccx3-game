#ifdef ENABLE_TDD
//
//  SpineTest.h
//
//
#ifndef __TDD_SpineTest__
#define __TDD_SpineTest__

// Include Header

#include "TDDTest.h"
#include <spine/spine-cocos2dx.h>

using namespace spine;

// Class Declaration 
class SpineTest : public TDDTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void setSubTest(Array *menuArray);
	
	void changeAnime(Object *sender, Control::EventType type);
	
private:
	void testSimple(Object *sender);
	void testChangeAnimation(Object *sender);
	
	
private:
	SkeletonAnimation *mAnime;
}; 

#endif

#endif

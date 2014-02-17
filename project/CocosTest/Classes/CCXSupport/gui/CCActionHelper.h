//
//  CCActionHelper.h
//  Dg
//
//  Created by Ken Lee on 23/1/14.
//
//

#ifndef __Dg__CCActionHelper__
#define __Dg__CCActionHelper__

#include <iostream>

#include "cocos2d.h"

USING_NS_CC;

class CCActionHelper
{
public:
	enum class Dir
	{
		eTop,
		eBottom,
		eLeft,
		eRight,
	};
public:
	static FiniteTimeAction *createMoveInAndFade(Node *node,
												 float moveInTime, float delayTime,
												 float fadeTime, bool autoRemove,
												 const std::function<void()> &func = false) ;
	static FiniteTimeAction *createMoveIn(Node *node, float moveInTime,
												   const std::function<void()> &func = false) ;

};

#endif /* defined(__Dg__CCActionHelper__) */

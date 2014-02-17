//
//  CCInfo.h
//  Dg
//	Information of the cocos data 
//
//  Created by Ken Lee on 28/12/13.
//
//

#ifndef __Dg__CCInfo__
#define __Dg__CCInfo__

#include <iostream>
#include <string>
#include "cocos2d.h"

USING_NS_CC;

class CCInfo
{
public:
	static std::string infoPoint(const Point &point);
	static std::string infoTouch(Touch *touch);
};

#endif /* defined(__Dg__CCInfo__) */

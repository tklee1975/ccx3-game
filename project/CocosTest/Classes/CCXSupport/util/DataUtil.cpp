//
//  DataUtil.cpp
//  Dg
//
//  Created by Ken Lee on 26/12/13.
//
//

#include "DataUtil.h"
#include <stdlib.h>
#include "MacroHelper.h"
#include "cocos2d.h"

USING_NS_CC;

int DataUtil::randInt(int min, int max)
{
	if(min == max) {
		return min;
	}
	
	// kenlee: cannot use std:rand in Android
#if IS_IOS
	// log("random using std::rand");
	return std::rand() % (max - min + 1) + min;
#else
	// log("random using arc4random");
	return arc4random() % (max - min) + min;
#endif
	
}
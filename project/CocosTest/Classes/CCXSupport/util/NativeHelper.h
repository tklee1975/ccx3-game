//
//  NativeHelper.h
//  Dg
//
//  Created by Ken Lee on 15/1/14.
//
//

#ifndef __Dg__NativeHelper__
#define __Dg__NativeHelper__

#include <iostream>

#define kJsonMethodName		"method_name"
#define kJsonMethodParam	"method_param"


#include "cocos2d.h"

USING_NS_CC;

class NativeHelper
{
public:
	static Object *callToNative(const std::string methodName, Object *param = NULL);
};

#endif /* defined(__Dg__NativeHelper__) */

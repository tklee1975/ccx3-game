//
//  DeviceHelper.h
//  Dg
//
//  Created by Ken Lee on 16/1/14.
//
//

#ifndef __Dg__DeviceHelper__
#define __Dg__DeviceHelper__

#include <iostream>

#include "cocos2d.h"

USING_NS_CC;

#define kDesignWidth	320
#define kDesignHeight	480

class DeviceHelper
{
public:
	static std::string getModelName();
	static std::string getDeviceID();
	static Size getDesignSize();
	static Size getWinSize();
	static std::string getResolutionInfo();
	static Point getViewOffset();
};

#endif /* defined(__Dg__DeviceHelper__) */

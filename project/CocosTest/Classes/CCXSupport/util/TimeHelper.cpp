//
//  TimeHelper.cpp
//  Dg
//
//  Created by Ken Lee on 31/12/13.
//
//

#include "TimeHelper.h"

#include "cocos2d.h"

USING_NS_CC;


// reference:
// http://fanqiang.chinaunix.net/a4/b8/20010527/201001267.html
// 1 microsecond = 0.001 milliseconds
// author: kenlee
long long TimeHelper::currentTimeMillis()
{
    struct timeval now;
    gettimeofday(&now, nullptr);
	
	long long result = ((long long) now.tv_sec) * 1000;		// second -> milliSecond
	result += now.tv_usec / 1000;							// micro-second -> milli-second
		
    return result;
	
}

double TimeHelper::currentTimeSecond()
{
	struct timeval now;
    gettimeofday(&now, nullptr);
	
	double result = (double) now.tv_sec;
	result += (double) now.tv_usec / 1000000;
	
    return result;
}
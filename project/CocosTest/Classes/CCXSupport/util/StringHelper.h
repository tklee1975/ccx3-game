//
//  StringHelper.h
//  Dg
//
//  Created by Ken Lee on 30/12/13.
//
//

#ifndef __Dg__StringHelper__
#define __Dg__StringHelper__

#include <iostream>
#include <vector>
#include <map>
#include <string>

#include "cocos2d.h"

USING_NS_CC;
using namespace std;

class StringHelper
{
public:
	static string joinInt(const vector<int> &intList, const string sep = ", ");

	static string joinIntStringMap(map<int, string> &map, const string sep =", ");
	
	static string ccobjectToStr(Object *obj);

	static string color3BToStr(Color3B &color);
	
	static string pointToStr(const cocos2d::Point &point);
};

#endif /* defined(__Dg__StringHelper__) */

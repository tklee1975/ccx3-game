//
//  JSONHelper.h
//  Dg
//
//  Created by Ken Lee on 15/1/14.
//
//

#ifndef __Dg__JSONHelper__
#define __Dg__JSONHelper__

#include <iostream>

#include "cocos2d.h"
#include <string>
#include <vector>
#include "jansson.h"

USING_NS_CC;
using namespace std;

class JSONHelper
{
	
public:
	// Helper for Janson JSON
	static std::string jsonToString(json_t *obj);
	static json_t *stringToJson(const std::string &str);
	
	static Object *jsonToObject(json_t *obj);
	static json_t *objectToJson(Object* obj);
	
	static std::string objectToJsonString(Object* obj);
	static Object *jsonStringToObject(const std::string &input);
};

//

#endif /* defined(__Dg__JSONHelper__) */

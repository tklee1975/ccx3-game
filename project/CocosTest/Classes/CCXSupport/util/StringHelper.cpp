//
//  StringHelper.cpp
//  Dg
//
//  Created by Ken Lee on 30/12/13.
//
//

#include "StringHelper.h"

#include <sstream>

string StringHelper::joinInt(const vector<int> &intList, const string sep)
{

	string result = "";
	char temp[50];
	  
	for(int i=0; i<intList.size(); i++) {
		if(i > 0) {
			result.append(sep);
		}
	  
		sprintf(temp, "%d", intList[i]);
	  
		result.append(temp);
	}
  
  
	return result;
}

string StringHelper::ccobjectToStr(Object *obj)
{
	if(obj == NULL) {
		return "";
	}
		
	if (dynamic_cast<Dictionary*>(obj))
    {
        Dictionary *dict = (Dictionary*)obj;
        Array *allKeys = dict->allKeys();

        string result = "{";
		
        if(allKeys != NULL ) {
			for (unsigned int i = 0; i < allKeys->count(); i++)
			{
				// break
				if(i != 0) {
					result.append(",\n");
				}

				
				// content
				String *key = (String *) allKeys->getObjectAtIndex(i);
				Object *obj = dict->objectForKey(key->getCString());
				
				string objStr = ccobjectToStr(obj);
				
				result.append(key->getCString());
				result.append(":");
				result.append(objStr);
			}
		}
		
		result.append("}");
        
        return result;
    }
    else if (dynamic_cast<Array *>(obj))
    {
        Array* array = (Array*)obj;
        
		string result = "[";
		
        for (unsigned int i = 0; i < array->count(); i++)
        {
			if(i != 0) {
				result.append(",\n");
			}
			
			Object *obj = array->getObjectAtIndex(i);
			result.append(ccobjectToStr(obj));
        }
		result.append("]");
        
        return result;
    }
    else if (dynamic_cast<String *>(obj))
    {
        String * str = (String*)obj;
        return string(str->getCString());
    }
	
	return "";
}

string StringHelper::joinIntStringMap(map<int, string> &map, const string sep)
{
	string result = "";
	
	char temp[200];
	
	for (std::map<int, string>::iterator it=map.begin(); it!=map.end(); ++it) {
		int key = it->first;
		string value = it->second;
		
		if(result.length() != 0) {
			result.append(sep);
		}
		
		sprintf(temp, "%d=%s", key, value.c_str());
		
		result.append(temp);
	}
//		std::cout << it->first << " => " << it->second << '\n';

	
	return result;
}

string StringHelper::color3BToStr(Color3B &color)
{
	string result = "";
	
	char temp[200];
	
	sprintf(temp, "(r:%d g:%d b:%d)", color.r, color.g, color.b);
	
	result.append(temp);
	
	return result;
}

string StringHelper::pointToStr(const cocos2d::Point &point)
{
	string result = "";
	
	char temp[100];
	
	sprintf(temp, "(x:%.4f y:%.4f)", point.x, point.y);
	
	result.append(temp);
	
	return result;
}
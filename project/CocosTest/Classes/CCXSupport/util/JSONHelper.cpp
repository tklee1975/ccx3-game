//
//  JSONHelper.cpp
//  Dg
//
//  Created by Ken Lee on 15/1/14.
//
//

#include "JSONHelper.h"


std::string JSONHelper::jsonToString(json_t *json)
{
	char *output = json_dumps(json, JSON_COMPACT | JSON_ENSURE_ASCII);
	if(output == NULL) {
		return "";
	}
	
	std::string result(output);
	
	free(output);
	
	return result;
}

Object *JSONHelper::jsonToObject(json_t *obj)
{
    if (obj == NULL) {
        return NULL;
	}
    
    if (json_is_object(obj))
    {
        //CCDictionary *dictionary = new CCDictionary();
        Dictionary *dictionary = Dictionary::create();
        
        const char *key;
        json_t *value;
        
        void *iter = json_object_iter(obj);
        while(iter)
        {
            key = json_object_iter_key(iter);
            value = json_object_iter_value(iter);
            
            dictionary->setObject(jsonToObject(value), string(key));
            
            iter = json_object_iter_next(obj, iter);
        }
        
        return dictionary;
    }
    else if (json_is_array(obj))
    {
        size_t sizeArray = json_array_size(obj);
        
        Array *array = Array::create();
		
        
        for (unsigned int i = 0; i < sizeArray; i++)
        {
			json_t *childObj = json_array_get(obj, i);
            array->addObject(jsonToObject(childObj));
        }
        
        return array;
    }
    else if (json_is_boolean(obj))
    {
		return String::create(json_is_true(obj) ? "true" : "false");
    }
    else if (json_is_integer(obj))
    {
		return String::createWithFormat("%lld", json_integer_value(obj));
    }
    else if (json_is_real(obj))
    {
		return String::createWithFormat("%f", json_real_value(obj));
    }
    else if (json_is_string(obj))
    {
		return String::create(json_string_value(obj));
    }
    
    return NULL;
}


json_t* JSONHelper::objectToJson(Object* obj)
{
    if (dynamic_cast<Dictionary *>(obj))
    {
        Dictionary *mainDict = (Dictionary *) obj;
        Array *allKeys = mainDict->allKeys();
        json_t* jsonDict = json_object();
        
        if(allKeys == NULL ) {
			return jsonDict;
		}
		
        for (unsigned int i = 0; i < allKeys->count(); i++)
        {
			
            const char *key = ((String *) allKeys->getObjectAtIndex(i))->getCString();
			Object *childObj = mainDict->objectForKey(key);
			
            json_object_set_new(jsonDict, key, objectToJson(childObj));
        }
        
        return jsonDict;
    }
    else if (dynamic_cast<Array*>(obj))
    {
        Array* mainArray = (Array*)obj;
        json_t* jsonArray = json_array();
        
        for (unsigned int i = 0; i < mainArray->count(); i++)
        {
			Object *childObj = mainArray->getObjectAtIndex(i);
            json_array_append_new(jsonArray, objectToJson(childObj));
        }
        
        return jsonArray;
    }
    else if (dynamic_cast<String*>(obj))
    {
        String* mainString = (String*)obj;
        json_t* jsonString = json_string(mainString->getCString());
        
        return jsonString;
    }
    
    return NULL;
}

json_t *JSONHelper::stringToJson(const std::string &str)
{

	json_error_t error;
	json_t *root;
	
	root = json_loads(str.c_str(), 0, &error);
	
	if (!root)
	{
		log("stringToJson: error: on line %d: %s\n", error.line, error.text);
		log("stringToJson: json=%s", str.c_str());
	}

	return root;
}

std::string JSONHelper::objectToJsonString(Object* obj)
{
	json_t *json = objectToJson(obj);
	
	std::string result = jsonToString(json);
	
	json_decref(json);
	
	return result;
}

Object *JSONHelper::jsonStringToObject(const std::string &input)
{
	
	json_t *json = stringToJson(input);
	
	Object *result = jsonToObject(json);
	
	// Release the object
	json_decref(json);

	return result;
}
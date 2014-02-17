//
//  NativeHelper.cpp
//  Dg
//
//  Created by Ken Lee on 15/1/14.
//
//

#include "NativeHelper.h"
#include "JSONHelper.h"
#include "MacroHelper.h"




#if IS_ANDROID
#define __ANDROID
// the real location of JniHelper: /dg/cocos/2d/platform/android/jni/JniHelper.h
#include "jni/JniHelper.h"
#endif


#if IS_IOS
#define __IOS
#include "NativeCInterface.h"
#endif


#pragma mark -
#pragma mark Local Functions

#define kAndroidClass	"com.aurora.NativeHelper"
#define kAndroidMethod	"runMethod"

namespace {
#ifdef __ANDROID
	std::string callAndroidMethod(const char *clsName,
								 const char *methodName,
								 const char *param)
	{
		JniMethodInfo mInfo;
        bool hasMethod = JniHelper::getStaticMethodInfo(mInfo, clsName,
														methodName,
														"(Ljava/lang/String;)Ljava/lang/String;");
        if(! hasMethod) {
			log("callAndroidMethod: no such method(%s.%s)", clsName, methodName);
            return "";        // XXX: should throws exceptions ??!!
        }
		
        jstring result;
		jstring arg1 = mInfo.env->NewStringUTF(param ? param : "");
        result = (jstring) mInfo.env->CallStaticObjectMethod(
															 mInfo.classID, mInfo.methodID, arg1);
		
		
		// Turn the jstring to std::string
		std::string retStr = JniHelper::jstring2string(result);
		
		// Clean up
		mInfo.env->DeleteLocalRef(arg1);
        mInfo.env->DeleteLocalRef(mInfo.classID);
		mInfo.env->DeleteLocalRef(result);
		
		// return
		return retStr;

	}
#endif
	
#ifdef __IOS
	std::string callIOSMethod(const char *clsName,
								  const char *methodName,
								  const char *param)
	{
		return "not yet";
	}
#endif
	
	// Call a static method in Java Code
    std::string callNativeMethod(const char *clsName,
												  const char *methodName,
												  const char *param)
    {
		std::string result = "";
	
#ifdef __ANDROID
		result = callAndroidMethod(clsName, methodName, param);
#endif

#ifdef __IOS
		result = callIOSMethod(clsName, methodName, param);
#endif

		
		return result;
	}
	
	std::string callToNativeBridge(const char *jsonContent)
	{

		if(IS_ANDROID) {
			return callNativeMethod(kAndroidClass, kAndroidMethod, jsonContent);
		} else if (IS_IOS) {
			return "";
		} else {
			return "";
		}
	}
}

#pragma mark -
#pragma mark NativeHelper Logic

Object *NativeHelper::callToNative(const std::string methodName, Object *param)
{
	if(param == NULL) {
		param = Dictionary::create();	// an empty param
	}
	
	// Construct the json
	Dictionary *jsonDic = Dictionary::create();
	jsonDic->setObject(String::create(methodName), kJsonMethodName);
	jsonDic->setObject(param, kJsonMethodParam);
	
	
#if IS_ANDROID
	std::string jsonContent = JSONHelper::objectToJsonString(jsonDic);
	
	log("jsonContent: %s", jsonContent.c_str());

	// result = callToNativeBridge(
	
	// std::string result = callNativeMethod(kA)
	std::string result = callToNativeBridge(jsonContent.c_str());
	
	return JSONHelper::jsonStringToObject(result);
#endif /* IS_ANDROID */
	
#if IS_IOS
	return IOSNativeInterface::doMethod(jsonDic);
#endif
	
	
	
	return NULL;
}
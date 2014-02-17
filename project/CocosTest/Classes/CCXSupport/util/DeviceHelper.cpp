//
//  DeviceHelper.cpp
//  Dg
//
//  Created by Ken Lee on 16/1/14.
//
//

#include "DeviceHelper.h"
#include "NativeHelper.h"


namespace {
	std::string getStringFromDic(Object *input, const std::string &key) {
		if(input == NULL) {
			return "";
		}
		
		Dictionary *dic = (Dictionary *) input;
		
		String *value = (String *)dic->objectForKey(key);
		if(value == NULL) {
			return "";
		}
		
		return std::string(value->getCString());
	}
	
	
}



std::string DeviceHelper::getModelName()
{
	
	Object *result = NativeHelper::callToNative("getModelName");
	
	return getStringFromDic(result, "modelName");
}


std::string DeviceHelper::getDeviceID()
{
	
	Object *result = NativeHelper::callToNative("getDeviceUID");
	
	return getStringFromDic(result, "uid");
}

Size DeviceHelper::getDesignSize()
{
	return Size(kDesignWidth, kDesignHeight);
}

Size DeviceHelper::getWinSize()
{
	return Director::getInstance()->getWinSize();
}


Point DeviceHelper::getViewOffset()
{
	Size mySize = getDesignSize();
	Size designSize = EGLView::getInstance()->getDesignResolutionSize();
	
	float ratioMe = mySize.height / mySize.width;
	float ratioDesign = designSize.height / designSize.width;
	
//	log("me= %.0f x %.0f (%.4f) ", mySize.width, mySize.height, ratioMe);
//	log("design= %.0f x %.0f (%.4f) ", designSize.width, designSize.height, ratioDesign);
	
	
	float x = 0;
	float y = 0;
	
	if(ratioMe < ratioDesign)
	{
		x = 0;
		y = (designSize.height - mySize.height) / 2;
	} else {
		x = (designSize.width - mySize.width) / 2;
		y = 0;
	}
	
	// log("offset=%f,%f", x, y);
	
	return Point(x, y);
}

std::string DeviceHelper::getResolutionInfo()
{
	Size mySize = getDesignSize();
	Size designSize = EGLView::getInstance()->getDesignResolutionSize();
	Size frameSize = EGLView::getInstance()->getFrameSize();
	Size winSize = Director::getInstance()->getWinSize();
	
	float ratioMe = mySize.height / mySize.width;
	float ratioDesign = designSize.height / designSize.width;
	float ratioFrame = frameSize.height / frameSize.width;
	float ratioWin = winSize.height / winSize.width;
	
	String *str = String::create("Resolution Info: ");
	
	str->appendWithFormat(" me= %.0f x %.0f (%.4f) ", mySize.width, mySize.height, ratioMe);
	str->appendWithFormat("/ design= %.0f x %.0f (%.4f) ", designSize.width, designSize.height, ratioDesign);
	str->appendWithFormat("/ frame= %.0f x %.0f (%.4f) ", frameSize.width, frameSize.height, ratioFrame);
	str->appendWithFormat("/ win= %.0f x %.0f (%.4f) ", winSize.width, winSize.height, ratioWin);
	
	return std::string(str->getCString());
}

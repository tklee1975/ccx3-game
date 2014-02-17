//
//  CCInfo.cpp
//  Dg
//
//  Created by Ken Lee on 28/12/13.
//
//

#include "CCInfo.h"

///** returns the current touch location in OpenGL coordinates */
//Point getLocation() const;
///** returns the previous touch location in OpenGL coordinates */
//Point getPreviousLocation() const;
///** returns the start touch location in OpenGL coordinates */
//Point getStartLocation() const;
///** returns the delta of 2 current touches locations in screen coordinates */
//Point getDelta() const;
///** returns the current touch location in screen coordinates */
//Point getLocationInView() const;
///** returns the previous touch location in screen coordinates */
//Point getPreviousLocationInView() const;
///** returns the start touch location in screen coordinates */
//Point getStartLocationInView() const;
std::string CCInfo::infoPoint(const Point &point)
{
	char temp[50];
	
	sprintf(temp, "%5.5f,%5.5f", point.x, point.y);
	
	return std::string(temp);
}

std::string CCInfo::infoTouch(Touch *touch)
{
	String *str = String::create("");
	
	if(touch == NULL) {
		str->append("touch is NULL");
	} else {
		str->append("now.gl=");
		str->append(infoPoint(touch->getLocation()));
		
		str->append(" last.gl=");
		str->append(infoPoint(touch->getPreviousLocation()));
		
		str->append(" start.gl=");
		str->append(infoPoint(touch->getStartLocation()));
		
		str->append(" delta=");
		str->append(infoPoint(touch->getDelta()));
		
		str->append(" now.view=");
		str->append(infoPoint(touch->getLocationInView()));
		
		str->append(" last.view=");
		str->append(infoPoint(touch->getPreviousLocationInView()));
		
		str->append(" start.view=");
		str->append(infoPoint(touch->getStartLocationInView()));
		
	}
	
	return std::string(str->getCString());
}
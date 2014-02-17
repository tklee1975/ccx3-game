//
//  TouchableLayer.cpp
//  Dg
//
//  Created by Ken Lee on 28/12/13.
//
//

#include "TouchableLayer.h"

TouchableLayer::TouchableLayer(const Color4B &color, int width, int height)
: mDelegate(NULL)
{
	initWithColor(color, width, height);
	
	this->setTouchEnabled(true);
	this->setTouchMode(Touch::DispatchMode::ONE_BY_ONE);	// ???
}

TouchableLayer::~TouchableLayer()
{
	
}

bool TouchableLayer::onTouchBegan(Touch *touch, Event *event)
{
	if(mDelegate == NULL) {
		return false;
	}

	Point posGL = touch->getLocation();			// from bottom
	Point nodeLoc = convertToNodeSpace(posGL);

	return mDelegate->handleTouchBegan(this, nodeLoc, touch);
}

void TouchableLayer::onTouchMoved(Touch *touch, Event *event)
{
	return;
}

void TouchableLayer::onTouchEnded(Touch *touch, Event *event)
{
	if(mDelegate) {
		Point posGL = touch->getLocation();			// from bottom
		Point nodeLoc = convertToNodeSpace(posGL);
		
		return mDelegate->handleTouchEnded(this, nodeLoc, touch);
	}
	return;
}

void TouchableLayer::onTouchCancelled(Touch *touch, Event *event)
{
	return;
}

bool TouchableLayer::isInsideLayer(const Point &locationInNode)
{
	float x = locationInNode.x;
	float y = locationInNode.y;
	Size size = this->getContentSize();
	
	if(x < 0 || x > size.width) {
		return false;
	}
	
	if(y < 0 || y > size.height) {
		return false;
	}
	
	
	return true;
}
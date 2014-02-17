//
//  PopupLayer.cpp
//  Dg
//
//  Created by Ken Lee on 24/1/14.
//
//

#include "PopupLayer.h"

namespace
{
	bool isInsideNode(Node *targetNode, Touch *touch)
	{
		// Check against the area
		Point locationInNode = targetNode->convertToNodeSpace(touch->getLocation());
		
        Size s = targetNode->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        
        return rect.containsPoint(locationInNode);
	}
}

#pragma mark - 
#pragma mark Static Method

PopupLayer * PopupLayer::create(const Color4B& color, GLfloat width, GLfloat height)
{
    PopupLayer * pLayer = new PopupLayer();
    if( pLayer && pLayer->initWithColor(color,width,height))
    {
        pLayer->autorelease();
        return pLayer;
    }
    CC_SAFE_DELETE(pLayer);
    return NULL;
}

PopupLayer * PopupLayer::create(const Color4B& color)
{
    PopupLayer * pLayer = new PopupLayer();
    if( pLayer && pLayer->initWithColor(color))
    {
        pLayer->autorelease();
        return pLayer;
    }
    CC_SAFE_DELETE(pLayer);
    return NULL;
}

PopupLayer * PopupLayer::create()
{
    PopupLayer * pLayer = new PopupLayer();
    if( pLayer && pLayer->init())
    {
        pLayer->autorelease();
        return pLayer;
    }
    CC_SAFE_DELETE(pLayer);
    return NULL;
}

#pragma mark -
#pragma mark Constructor & Destructor


PopupLayer::PopupLayer()
: mDelegate(NULL)
{
	attachListener();
}

PopupLayer::~PopupLayer()
{
	
}

bool PopupLayer::init()
{
	Size s = Director::getInstance()->getWinSize();
    return initWithColor(Color4B(0,0,0,0), s.width, s.height);
}


bool PopupLayer::initWithColor(const Color4B& color)
{
	Size s = Director::getInstance()->getWinSize();
    return initWithColor(color, s.width, s.height);
	
}


bool PopupLayer::initWithColor(const Color4B& color, GLfloat width, GLfloat height)
{
	if (LayerColor::initWithColor(color, width, height))
    {
		
		return true;
	}
	
	return false;
}

#pragma mark -
#pragma mark Event Handling

bool PopupLayer::onTouchBegan(Touch* touch, Event* event)
{
	// log("onTouchBegan!! ");
	return true;
}

void PopupLayer::onTouchMoved(Touch* touch, Event* event)
{
	// log("onTouchMoved!! ");
}

void PopupLayer::onTouchEnded(Touch* touch, Event* event)
{
	// log("onTouchEnded!! ");
}

void PopupLayer::attachListener()
{
	auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
	
	listener->onTouchBegan = [](Touch* touch, Event* event)
	{
		PopupLayer *target = static_cast<PopupLayer *>(event->getCurrentTarget());
		
		if(target == NULL) {
			return false;
		}
		
		if(isInsideNode(target, touch) == false) {
			return false;
		}
		
		target->onTouchBegan(touch, event);
		return true;
	};
	
	listener->onTouchMoved = [](Touch *touch, Event *event)
	{
		PopupLayer *target = static_cast<PopupLayer *>(event->getCurrentTarget());
		if(target) {
			target->onTouchMoved(touch, event);
		}
	};

	listener->onTouchEnded = [](Touch *touch, Event *event)
	{
		PopupLayer *target = static_cast<PopupLayer *>(event->getCurrentTarget());
		if(target) {
			target->onTouchEnded(touch, event);
		}
	};

	
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	//
}

void PopupLayer::onExit()
{
	log("PopupLayer::onExit");
	if(mDelegate) {
		mDelegate->popupLayerWillClose(this);
	}
	
	LayerColor::onExit();
}
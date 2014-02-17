//
//  PopupLayer.h
//  Dg
//
//  Created by Ken Lee on 24/1/14.
//
//

#ifndef __Dg__PopupLayer__
#define __Dg__PopupLayer__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class PopupLayer;

class PopupLayerDelegate
{
public:
    /**
     */
    virtual ~PopupLayerDelegate() {}
    
	/**
     */
	
    virtual void popupLayerWillClose(PopupLayer *layer) = 0;
};

class PopupLayer : public LayerColor
{
public:
	
	/** creates a fullscreen black layer */
    static PopupLayer* create();
    /** creates a Layer with color, width and height in Points */
    static PopupLayer * create(const Color4B& color, GLfloat width, GLfloat height);
    /** creates a Layer with color. Width and height are the window size. */
    static PopupLayer * create(const Color4B& color);
	
    /**
     * @js ctor
     */
    PopupLayer();
    
	/**
     * @js NA
     * @lua NA
     */
    virtual ~PopupLayer();
	
    virtual bool init();
    /** initializes a Layer with color, width and height in Points
     * @js init
     * @lua init
     */
    bool initWithColor(const Color4B& color, GLfloat width, GLfloat height);
    /** initializes a Layer with color. Width and height are the window size.
     * @js init
     * @lua init
     */
    bool initWithColor(const Color4B& color);

	// Exit
	virtual void onExit();
	
	// Event !!!
	virtual bool onTouchBegan(Touch* touch, Event* event);
	virtual void onTouchMoved(Touch* touch, Event* event);
	virtual void onTouchEnded(Touch* touch, Event* event);
	
	
	bool isInsideLayer(const Point &locationInNode);
	
	CC_SYNTHESIZE(PopupLayerDelegate *, mDelegate, Delegate);
	
protected:
	void attachListener();
	
};

#endif /* defined(__Dg__PopupLayer__) */

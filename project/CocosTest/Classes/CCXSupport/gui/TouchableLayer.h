//
//  TouchableLayer.h
//  Dg
//
//  Created by Ken Lee on 28/12/13.
//
//

#ifndef __Dg__TouchableLayer__
#define __Dg__TouchableLayer__

#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

class TouchableLayer;

class TouchableLayerDelegate
{
public:
    /**
     */
    virtual ~TouchableLayerDelegate() {}
    
	/**
     */

    virtual bool handleTouchBegan(TouchableLayer *layer, const Point &location, Touch *touch) = 0;
    /**
     */
    virtual void handleTouchEnded(TouchableLayer *layer, const Point &location, Touch *touch) = 0;
};


class TouchableLayer : public LayerColor
{
public:
	TouchableLayer(const Color4B &color, int width, int height);
	virtual ~TouchableLayer();
	
    virtual bool onTouchBegan(Touch *touch, Event *event);
    virtual void onTouchMoved(Touch *touch, Event *event);
    virtual void onTouchEnded(Touch *touch, Event *event);
    virtual void onTouchCancelled(Touch *touch, Event *event);
	
	
	TouchableLayerDelegate* getDelegate() { return mDelegate; }
	
	bool isInsideLayer(const Point &locationInNode);
	
    /**
     * @code
     * when this function bound to js or lua,the input param are changed
     * in js: var setDelegate(var jsObject)
     * in lua: local setDelegate()
     * @endcode
     */
    void setDelegate(TouchableLayerDelegate* pDelegate) { mDelegate = pDelegate; }

protected:
	TouchableLayerDelegate* mDelegate;
};



#endif /* defined(__Dg__TouchableLayer__) */

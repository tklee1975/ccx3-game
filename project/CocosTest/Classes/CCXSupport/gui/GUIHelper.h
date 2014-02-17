//
//  GUIHelper.h
//  Dg
//
//  Created by Ken Lee on 25/12/13.
//
//

#ifndef __Dg__GUIHelper__
#define __Dg__GUIHelper__

#include "cocos2d.h"
#include "cocos-ext.h"
#include <string>
#include <vector>

USING_NS_CC;
USING_NS_CC_EXT;

#define kTagPoint		100000
#define kZOrderPoint	100000

class GUIHelper
{
public:
	static Menu *createSimpleMenu(const std::string &name,
										const ccMenuCallback& callback,
										const Point &pos);
	
	static ControlButton *createButton(const std::string &name,
									   Object *target,
									   Control::Handler handler,
									   const Point &pos);
	
	static ControlButton *createButton(const std::string &name,
									   Object *target,
									   Control::Handler handler,
									   const Point &pos, const Size &size);
	
	static int addNodesToParent(Node *parent, std::vector<Node *> &nodeArray,
										int x, int y, int maxWidth, int space);
	
	
	static void addPoint(Node *parent,  Point point,
						 int zOrder = kZOrderPoint,
						 int tag = kTagPoint,
						 Color4B color=Color4B::RED, int pointSize=5);
	
	static void addAnchorPoint(Node *parent, std::vector<Node *>targetNodes);
};

#endif /* defined(__Dg__GUIHelper__) */

//
//  GUIHelper.cpp
//  Dg
//
//  Created by Ken Lee on 25/12/13.
//
//

#include "GUIHelper.h"

#define kFont				"Arial"
#define kFontSize			20

#define kColorButtonNormal			Color3B(255, 255, 255)

#define kSpriteButtonNormal			"button1.png"
#define kSpriteButtonHighlight		"button1_on.png"
#define kSpriteButtonDisable		"button1_off.png"

Menu *GUIHelper::createSimpleMenu(const std::string &name,
								  const ccMenuCallback& callback,
								  const Point &pos)
{
	// static MenuItemFont * create(const std::string& value, const ccMenuCallback& callback);
	MenuItemFont *menuItem = MenuItemFont::create(name, callback);
	
	Menu *menu = Menu::create(menuItem, NULL);
    menu->alignItemsVertically();
	menu->setPosition(pos);
    
	return menu;
}


ControlButton *GUIHelper::createButton(const std::string &name,
									   Object *target,
									   Control::Handler handler,
									   const Point &pos, const Size &size)
{
	auto spriteNormal = Scale9Sprite::create(kSpriteButtonNormal);
	auto spriteHighlight = Scale9Sprite::create(kSpriteButtonHighlight);
	auto spriteDisable = Scale9Sprite::create(kSpriteButtonDisable);
	
	auto label = LabelTTF::create(name, kFont, kFontSize);
	label->setColor(kColorButtonNormal);
	
	ControlButton *button = ControlButton::create(label, spriteNormal);
	button->setBackgroundSpriteForState(spriteHighlight, Control::State::HIGH_LIGHTED);
	button->setBackgroundSpriteForState(spriteDisable, Control::State::DISABLED);
	button->addTargetWithActionForControlEvents(target, handler, Control::EventType::TOUCH_UP_INSIDE);
	
	button->setPreferredSize(size);
	button->setPosition(pos.x, pos.y);
	
	return button;
}

ControlButton *GUIHelper::createButton(const std::string &name,
									   Object *target,
									   Control::Handler handler,
									   const Point &pos)
{
	Size size = Size(80, 36);
	return GUIHelper::createButton(name, target, handler, pos, size);
}

void GUIHelper::addPoint(Node *parent, Point point, int tag, int zOrder, Color4B color, int pointSize)
{
	if(parent == NULL) {
		return;
	}
	
	float halfSize = (float) pointSize / 2;
	Point startPoint = Point(point.x - halfSize, point.y - halfSize);
	
	LayerColor *layer = LayerColor::create(color, pointSize, pointSize);
	layer->setPosition(startPoint);
	
	parent->addChild(layer, zOrder);
}

void GUIHelper::addAnchorPoint(Node *parent, std::vector<Node *>targetNodes)
{
	for(int i=0; i<targetNodes.size(); i++) {
		Node *node = targetNodes[i];
		
		if(node) {
			addPoint(parent, node->getPosition());
		}
	}
}

int GUIHelper::addNodesToParent(Node *parent, std::vector<Node *> &nodeArray,
									int x, int y, int maxWidth, int space)
{
	int maxH = 0;
	int startX = x;
	
	int viewW = maxWidth;
	
	log("addNodesToParent: y=%d A", y);
	
	// Find the position fire
	std::vector<Point> posArray;		// all point are using left-bottom cornder
	
	for(int i=0; i<nodeArray.size(); i++) {
		Node *node = nodeArray[i];
		Size size = node->getContentSize();
		size.width *= node->getScaleX();
		size.height *= node->getScaleY();
		
		// check for new line
		if(x + size.width > viewW) {
			x = startX;
			y += maxH + space;
			maxH = 0;
		}
		posArray.push_back(Point(x, y));
		
		maxH = MAX(size.height, maxH);
		
		x += size.width + space;
	}
	
	
	int totalH = y + maxH + space;
	log("addNodesToParent: y=%d B totalH=%d", y, totalH);

	
	// Adding the Nodes
	for(int i=0; i<nodeArray.size(); i++) {
		Node *node = nodeArray[i];
		Size size = node->getContentSize();
		Point anchor = node->getAnchorPoint();
		
		float offsetX = size.width * anchor.x;
		float offsetY = size.height * anchor.y;
		
		Point point = posArray[i];
		float px = point.x + offsetX;
		//float py = totalH - point.y - size.height + offsetY;
		float py = point.y + offsetY;	// totalH - point.y - size.height + offsetY;
		
		log("addNodesToParent: px=%f py=%f", px, py);
		
		node->setPosition(Point(px, py));
		parent->addChild(node);
	}
	
	return totalH;
	
}


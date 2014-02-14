//
//  TDDHelper.cpp
//  Dg
//
//  Created by Ken Lee on 13/12/13.
//
//

#include "TDDHelper.h"
#include "TDDSuite.h"

#ifdef ENABLE_TDD
#define HAS_TDD		true
#else
#define HAS_TDD		false
#endif

#define kTDDFilterKey	"tdd.filter.pattern"

static std::string sFilterPattern("");

Size TDDHelper::getScreenSize()
{
	auto glView = EGLView::getInstance();
	return glView->getDesignResolutionSize();
}

Point TDDHelper::getAlignPoint(float x, float y, TDDAlign halign, TDDAlign valign)
{
	Size size = getScreenSize();
	
	// Horizon
	if(halign == eTDDLeft) {
		x = size.width - x;
	} else if (halign == eTDDCenter) {
		x = size.width / 2 + x;
	}
	
	log("getAlignPoint: h=%f w=%f", size.height, size.width);
	
	// Vertical
	if(valign == eTDDTop) {
		y = size.height - y;
	} else if (valign == eTDDMiddle) {
		y = size.height / 2 + y;
	}
	
	 log("getAlignPoint: x=%f y=%f", x, y);
	
	return Point(x, y);
}

void TDDHelper::showTests()
{
#ifdef ENABLE_TDD
	Scene *scene = new TDDSuiteScene();
	
	Director::getInstance()->pushScene(scene);
	
	scene->release();
#endif
}

MenuItem *TDDHelper::createMenuItem(const char *name, const ccMenuCallback& callback)
{
	auto label = LabelTTF::create(name, kDefaultFont, kDefaultFontSize);
	
	auto menuItem = MenuItemLabel::create(label, callback);
	
	return menuItem;
}

Menu *TDDHelper::createMenu(Point pos, const char *name, const ccMenuCallback& callback)
{
	auto menuItem = createMenuItem(name, callback);
	Menu *menu = Menu::create(menuItem, NULL);
	menu->setPosition(pos);
	
	return menu;
}

void TDDHelper::addTestButton(Node *parent, Point pos)
{
	if(HAS_TDD == false) {
		log("ERROR: TDD Framework is disable!");
		return;
	}
	
	
	if(parent == NULL) {
		log("ERROR: addTestButton: parent is NULL");		// or use Assert
		return;
	}
	
	Menu *menu = createMenu(pos, "Test!", [](Object *sender) {
												TDDHelper::showTests();
											}
							);
	
	parent->addChild(menu);
}

void TDDHelper::scrollToTop(ScrollView *scrollView)
{
	Size containerSize = scrollView->getContainer()->getContentSize();
	
	Point offset = Point(0, -containerSize.height + scrollView->getViewSize().height);
	
	log("containerH=%f scrollH=%f", containerSize.height, scrollView->getViewSize().height);
	
	//[scrollView setContentOffset:offset animated:NO];
	scrollView->setContentOffset(offset);
}


Point TDDHelper::getCenter(Size &parentSize, Size &nodeSize)
{
	float x = (parentSize.width - nodeSize.width) / 2;
	float y = (parentSize.height - nodeSize.height) / 2;
	
	return Point(x, y);
}

EditBox * TDDHelper::createEditBox(Node *parent, Point position, Size size)
{
	Scale9Sprite *bg = Scale9Sprite::create();	// empty sprite 9

	// Add the background layer
	Point layerPos = Point(position);
	layerPos.x -= size.width / 2;
	layerPos.y -= size.height / 2;
	
	LayerColor *layer = LayerColor::create(Color4B::GRAY, size.width, size.height);
	layer->setPosition(layerPos);
	parent->addChild(layer);
	
	// Add the Edit box
	EditBox *box = EditBox::create(size, bg);
	box->setPosition(position);
	parent->addChild(box);
	
	return box;
}



void TDDHelper::saveFilter(const char *pattern)
{
	sFilterPattern = pattern;
	
	CCUserDefault::getInstance()->setStringForKey(kTDDFilterKey, pattern);
	log("Save filter %s for key=%s", pattern, kTDDFilterKey);
}

const char *TDDHelper::getFilter()
{
	sFilterPattern = CCUserDefault::getInstance()->getStringForKey(kTDDFilterKey);
	
	log("Load filter for key=%s result=%s",  kTDDFilterKey, sFilterPattern.c_str());
	
	return sFilterPattern.c_str();
}

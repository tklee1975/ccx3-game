#ifdef ENABLE_TDD
//
//  TDDTest.cpp
//  Dg
//
//  Created by Ken Lee on 13/12/13.
//
//

#include "TDDTest.h"
#include "extensions/cocos-ext.h"
#include "TDDHelper.h"
#include "TDDMenu.h"

#include <string>

#define kToolBarHeight		kDefaultToolbarHeight
#define kLineHeight			kDefaultMenuRowHeight

#define kAlpha				200
#define kColorTestMenu		Color4B(20, 20, 20, kAlpha)
#define kColorToolBar		Color4B(20, 20, 100, kAlpha)

#define kZOrderControlLayer	10000

#define kMenuWidthRatio		50
#define kMenuHeightRatio	80

#pragma mark -
#pragma mark Local Private Method

namespace {
	void removeNameSpace(const char *className, std::string &trimName)
	{
		std::string str(className);
		
		size_t pos = str.find_last_of("::");
		if(pos == std::string::npos) {
			trimName = std::string(className);
			return;
		}
		

		trimName = str.substr(pos+1);
	}
//
//	Size getScreenSize()
//	{
//		auto glView = EGLView::getInstance();
//        return glView->getDesignResolutionSize();
//	}
//	
//	Point getTopLeftPoint(float x, float y)
//	{
//		Point point = Point(x, y);
//		return Director::getInstance()->convertToGL(point);
//	}
//	
//	Point getAlignPoint(float x, float y, bool isTop, bool isRight)
//	{
//		Size size = getScreenSize();
//		
//		if(isRight) {
//			x = size.width - x;
//		}
//		
//		Point point = Point(x, y);
//
//		if(isTop == false) {	// bottom, use openGL position directly
//			return point;
//		}
//		
//		return Director::getInstance()->convertToGL(point);
//	}
}

#pragma mark -
#pragma mark TDDTest Scene
TDDTest::TDDTest(bool portrait, bool physics/* = false*/)
: mTDDMenu(NULL)
, mControlLayer(NULL)
{
#ifdef CC_USE_PHYSICS
	physics = true;
#endif
	
    if (physics)
    {
       //  TDDTest::initWithPhysics();
    }
	
   Scene::init();
}




bool TDDTest::showStat()
{
	return true;
}

void TDDTest::configTest()
{
	// Stat
	Director::getInstance()->setDisplayStats(showStat());
	
}

void TDDTest::resetConfig()
{
	Director::getInstance()->setDisplayStats(! showStat());
}


void TDDTest::setupGUI()
{
	setupControlLayer();
}

//void TDDTest::backToTestSuite()
//{
//	
//}

void TDDTest::setUp()
{
	log("TDDTest::setUp is called");
	
	LabelTTF *label = LabelTTF::create("Please code something!!", kDefaultFont, kDefaultFontSize);
	
	Size size = TDDHelper::getScreenSize();
	
	label->setPosition(Point(size.width/2, size.height/2));
	
	addChild(label);
}

void TDDTest::onEnter()
{
    Scene::onEnter();

	setupGUI();
	configTest();

	setUp();
	
}

void TDDTest::tearDown()
{
	// nothing yet
}

void TDDTest::onExit()
{
	resetConfig();
	
	tearDown();
	
    Scene::onExit();
}


void TDDTest::addSubTestMenu(Array *menuArray, const char *name, const ccMenuCallback& callback)
{
	// trim the "prefix before ::"
	std::string trimName;
	removeNameSpace(name, trimName);
	log("DEBUG: addSubTestMenu: %s", trimName.c_str());
	
	// Create menu and add it!!
	MenuItem *menuItem = TDDHelper::createMenuItem(trimName.c_str(), callback);
	menuArray->addObject(menuItem);
}


void TDDTest::sampleTest(Object *sender)
{
	log("sampleTest is called");
}

void TDDTest::setSubTest(Array *menuArray)
{
	// These are used during the development of the TDDTest
//	addSubTestMenu(menuArray, "Test1", CC_CALLBACK_1(TDDTest::sampleTest, this));
//	addSubTestMenu(menuArray, "Test2", CC_CALLBACK_1(TDDTest::sampleTest, this));
//	addSubTestMenu(menuArray, "Test3", CC_CALLBACK_1(TDDTest::sampleTest, this));
}




#pragma mark -
#pragma mark GUI
Menu *TDDTest::createBackMenu()
{
	auto label = LabelTTF::create("Back", kDefaultFont, kDefaultFontSize);
	
	
	MenuItemLabel *menuItem = MenuItemLabel::create(label,
										  [](Object *sender) {
											  log("createBackMenu: called");
											  Director::getInstance()->popScene();
										  }
										  );
	
	Menu *menu = Menu::create(menuItem, NULL);
	return menu;
}

void TDDTest::toggleMenu(Object *sender)
{
	log("TODO: Show/Hide the menu");
	MenuItemLabel *menuItem = static_cast<MenuItemLabel *>(sender);
	if(menuItem == NULL) {
		log("toggleMenu: menuItem is NULL");
		return;
	}
	
	bool newFlag = ! mMenuVisible;
	
	setMenuVisible(newFlag);

}

void TDDTest::hideMenu()
{
	setMenuVisible(false);
}

void TDDTest::setMenuVisible(bool flag)
{
	if(mTDDMenu) {
		mTDDMenu->setVisible(flag);
	}
	
	mMenuVisible = flag;
}

Menu *TDDTest::createToggleMenu()
{
	auto label = LabelTTF::create("Menu", kDefaultFont, kDefaultFontSize);
	
	MenuItemLabel *menuItem = MenuItemLabel::create(label, CC_CALLBACK_1(TDDTest::toggleMenu, this));
	
	setMenuVisible(true);		// default is true
	
	Menu *menu = Menu::create(menuItem, NULL);
	return menu;
}

void TDDTest::setupControlLayer()
{
	Size screenSize = TDDHelper::getScreenSize();	// assume the control layer same size as the parent layer
	
	Layer *layer = Layer::create();
	layer->setContentSize(screenSize);
	
	// Add the Menu
	TDDMenu *menu = createTDDMenu();		// autorelease
	if(menu) {
		Size menuSize = menu->getViewSize();
		float y = kToolBarHeight + menuSize.height;
		float x = screenSize.width - menuSize.width;
		Point point = Director::getInstance()->convertToGL(Point(x, y));	//TDDHelper::getCenter(screenSize, menuSize);
		menu->setPosition(point);
		layer->addChild(menu);
	}
	mTDDMenu = menu;
	bool hasMenu = mTDDMenu != NULL;

	// Add the toolbar
	LayerColor *toolBarLayer = createToolBarLayer(hasMenu);
	Point toolBarPos = Director::getInstance()->convertToGL(Point(0, kToolBarHeight));
	toolBarLayer->setPosition(toolBarPos);
	layer->addChild(toolBarLayer);
	mToolBarLayer = toolBarLayer;
		
	// Add to scene
	this->addChild(layer, kZOrderControlLayer);
}

TDDMenu *TDDTest::createTDDMenu()
{
	Array *menuArray = Array::create();
	setSubTest(menuArray);

	if(menuArray->count() == 0) {
		return NULL;
	}
	
	Size screenSize = TDDHelper::getScreenSize();
	float width = screenSize.width * kMenuWidthRatio / 100;
	float height = screenSize.height * kMenuHeightRatio / 100;

	Size menuSize = Size(width, height);
	
	TDDMenu *menu = new TDDMenu(menuSize, kColorTestMenu, kLineHeight);
	menu->autorelease();
	
	
	// Sample Data
	menu->setMenuItems(menuArray);
	

	return menu;
}

void TDDTest::toggleStat(Object *sender)
{
	Director *director = Director::getInstance();
	bool hasStat = director->isDisplayStats();
	director->setDisplayStats(! hasStat);
}

LayerColor *TDDTest::createToolBarLayer(bool hasMenu)
{
	Size screenSize = TDDHelper::getScreenSize();
	
	
	float width = screenSize.width;
	float height = kToolBarHeight;
	
	LayerColor *layer = LayerColor::create(kColorToolBar, width, height);
	

	// Add the back button
	Menu *backMenu = createBackMenu();
	backMenu->setPosition(Point(50, kToolBarHeight/2));
	layer->addChild(backMenu);
	
	// Toggle FPS Stat
	Point pos = Point(screenSize.width / 2, kToolBarHeight / 2);
	Menu *toggleStatMenu = TDDHelper::createMenu(pos, "Stat", CC_CALLBACK_1(TDDTest::toggleStat, this));
	layer->addChild(toggleStatMenu);
	
	// Add the toggle menu
	if(hasMenu) {
		Menu *toggleMenu = createToggleMenu();
		toggleMenu->setPosition(Point(screenSize.width - 50, kToolBarHeight/2));
		layer->addChild(toggleMenu);
	}
	
	
	return layer;
}

void TDDTest::hideToolBar()
{
	mToolBarLayer->setVisible(false);
}


void TDDTest::setToolBarOpacity(GLubyte value)
{
	mToolBarLayer->setOpacity(value);
}
#endif
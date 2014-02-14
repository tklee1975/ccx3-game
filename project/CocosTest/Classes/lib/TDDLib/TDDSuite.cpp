//
//  TTDSuite.cpp
//  Dg
//
//  Created by Ken Lee on 13/12/13.
//
//

#ifdef ENABLE_TDD

#include "TDDSuite.h"
#include "TDDTypes.h"
#include "TDDCases.h"
#include "TDDHelper.h"
#include "TDDMenu.h"

static int gTestCount = sizeof(gTestArray) / sizeof(gTestArray[0]);

#define kTestZOrder			10000
#define kLineHeight			kDefaultMenuRowHeight
#define kToolBarHeight		kDefaultToolbarHeight

#define kColorTestMenu		Color4B(50, 50, 100, 255)
#define kColorToolBar		Color4B(50, 100, 50, 255)

#pragma mark -
#pragma mark Local Function
namespace {
	bool passFilter(const char *name, const char *filterPattern)
	{
		if(strlen(filterPattern) == 0) {
			return true;
		}
		
		return strcasestr(name, filterPattern) != NULL;
	}
}

#pragma mark -
#pragma mark TDDSuiteScene
TDDSuiteScene::TDDSuiteScene()
{
	
}

TDDSuiteScene::~TDDSuiteScene()
{
	
}

void TDDSuiteScene::onEnter()
{
	log("TDDSuiteScene: onEnter");

	Scene::onEnter();
	
	log("TDDSuiteScene: onEnter is called");
	
	TDDSuiteLayer *layer = new TDDSuiteLayer();
	addChild(layer);
	layer->release();
	
	// Save the stat setting and then turn off
	hasStat = Director::getInstance()->isDisplayStats();
	Director::getInstance()->setDisplayStats(false);
	
}

void TDDSuiteScene::onExit()
{
	log("TDDSuiteScene: onExit");
	this->removeAllChildren();
	
	Director::getInstance()->setDisplayStats(hasStat);
	Scene::onExit();
}


#pragma mark -
#pragma mark TDDSuiteLayer

TDDSuiteLayer::TDDSuiteLayer()
: mEditFilter(NULL)
{
	setupTestMenu();
	setupToolBar();
	
	
}

TDDSuiteLayer::~TDDSuiteLayer()
{
	
}


void TDDSuiteLayer::goBack(Object * sender)
{
	log("goback to main");
	Director::getInstance()->popToRootScene();
}

void TDDSuiteLayer::filterTest(Object * sender)
{
	log("filterTest");
	
	const char *pattern = (mEditFilter == NULL) ? "" : mEditFilter->getText();
	
	TDDHelper::saveFilter(pattern);
	
	// Director::getInstance()->popToRootScene();
	refreshTestMenu();
}



Layer *TDDSuiteLayer::createToolBarLayer()
{
	Size screenSize = TDDHelper::getScreenSize();
	int midY = kToolBarHeight/2;
	int inputW = 140;
	int menuW = 70;
	
	int backX = 40;
	
	int findX  = screenSize.width - menuW/2;
	int inputH = kToolBarHeight - 10;
	int inputX = findX - 10 - menuW / 2  - inputW / 2;
	
	
	
	
	LayerColor *menuLayer = LayerColor::create(kColorToolBar, screenSize.width, kToolBarHeight);
	
	Menu *menuBack = TDDHelper::createMenu(Point(backX, midY), "Back",
										   CC_CALLBACK_1(TDDSuiteLayer::goBack, this));
	
	menuLayer->addChild(menuBack);
	
	
	
	mEditFilter = TDDHelper::createEditBox(menuLayer, Point(inputX, midY), Size(inputW, inputH));
	mEditFilter->setText(TDDHelper::getFilter());
	
	Menu *menuFind = TDDHelper::createMenu(Point(findX, midY), "Find",
										   CC_CALLBACK_1(TDDSuiteLayer::filterTest, this));
	
	menuLayer->addChild(menuFind);
	
	return menuLayer;
}

void TDDSuiteLayer::setupToolBar()
{
	Point pos = Point(0, kToolBarHeight);
	Layer *toolBar = createToolBarLayer();
	toolBar->setPosition(Director::getInstance()->convertToGL(pos));
	this->addChild(toolBar);
}

void TDDSuiteLayer::setupTestMenu()
{
	Size screenSize = TDDHelper::getScreenSize();
	Size menuSize = Size(screenSize.width, screenSize.height - kToolBarHeight);

	
	TDDMenu *menu = new TDDMenu(menuSize, kColorTestMenu, kLineHeight);
	this->addChild(menu);
	menu->release();
	
	// Set to the class variable
	mTestMenu = menu;
	
	// Refresh Menu Data
	refreshTestMenu();
}

const char *TDDSuiteLayer::getFilterName()
{
	return TDDHelper::getFilter();
}


void TDDSuiteLayer::refreshTestMenu()
{
	Array *menuArray = Array::createWithCapacity(gTestCount);
	
	
	// TODO: Filtering !!!!
	const char *filterPattern = getFilterName();
	
	MenuItem *menuItem;
	for (int i = 0; i < gTestCount; i++)
    {
		const char *name = gTestArray[i].name;
		if(passFilter(name, filterPattern) == false) {
			continue;
		}
		
		menuItem = TDDHelper::createMenuItem(name, CC_CALLBACK_1(TDDSuiteLayer::menuCallback, this));
		menuItem->setTag(i);	// this must be the index of the test in the gTestArray
		
		menuArray->addObject(menuItem);
    }
	
	mTestMenu->setMenuItems(menuArray);
}


#pragma mark -
#pragma mark Test Action Handling
void TDDSuiteLayer::runTest(int testIdx)
{
	
	if(testIdx < 0 || testIdx >= gTestCount) {
		log("ERROR: TDDSuteLayer.runTest: invalid index=%d", testIdx);
		return;
	}
	
	// create the test scene and run it
    auto scene = gTestArray[testIdx].callback();
	if (scene)
    {
		Director::getInstance()->pushScene(scene);
        scene->release();
    }
}

void TDDSuiteLayer::menuCallback(Object * sender)
{
	log("menuCallback: is called");
	MenuItem *item = dynamic_cast<MenuItem *>(sender);
	
	log("item tag=%d", item->getTag());
	runTest(item->getTag());
	
}



#endif
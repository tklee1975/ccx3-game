#ifdef ENABLE_TDD
//
//  TDDMenuTest.m
//	TDD Framework 
//
//
#include "TDDMenuTest.h"
#include "TDDHelper.h"
#include "TDDMenu.h"

void TDDMenuTest::callback(Object * sender)
{
	log("TDDMenuTest:callback is called");
	int count = mMenuArray->count();
	
	String *nameStr = String::createWithFormat("newMenu-%d", count);
	
	MenuItem *menuItem = TDDHelper::createMenuItem(nameStr->getCString(),
												   CC_CALLBACK_1(TDDMenuTest::callback, this));
	mMenuArray->addObject(menuItem);
	

	// update the menu items
	mMenu->setMenuItems(mMenuArray);
}

void TDDMenuTest::tearDown()
{
	CC_SAFE_RELEASE_NULL(mMenuArray);
}

void TDDMenuTest::setUp()
{
	log("TDD Setup is called");
	log("Please write somethings");
	
	//Size size = TDDHelper::getScreenSize();

	// Construct the array
	Array *menuArray = Array::create();
	menuArray->retain();
	mMenuArray = menuArray;
	
	for (int i = 0; i < 10; i++)
    {
		String *nameStr = String::createWithFormat("menu-%d", i);

		MenuItem *menuItem = TDDHelper::createMenuItem(nameStr->getCString(),
											 CC_CALLBACK_1(TDDMenuTest::callback, this));
		mMenuArray->addObject(menuItem);
    }
	
	
	TDDMenu *menu = new TDDMenu(Size(600, 1000), Color4B(100, 100, 200, 100), 80);
	this->addChild(menu);
	menu->release();
	mMenu = menu;
	
	// update the menu
	menu->setMenuItems(menuArray);
}

#endif
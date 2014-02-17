#ifdef ENABLE_TDD
//
//  GUIHelperTest.m
//	TDD Framework 
//
//
#include "GUIHelperTest.h"
#include "TDDHelper.h"
#include "GUIHelper.h"

void GUIHelperTest::setUp()
{
	log("TDD Setup is called");
	log("Please write somethings");
}


void GUIHelperTest::tearDown()
{
	log("TDD tearDown is called");
	log("Please do clean up here");
}

#pragma mark -
#pragma mark List of Sub Tests

void GUIHelperTest::setSubTest(Array *menuArray)
{
	SUBTEST(GUIHelperTest::subTest);
}

#pragma mark -
#pragma mark Sub Test Definition
void GUIHelperTest::subTest(Object *sender)
{
	log("this is a sample subTest");
	ControlButton *button = GUIHelper::createButton("test",
													this, cccontrol_selector(GUIHelperTest::onTestPressed),
													Point(200, 200), Size(100, 60));
	addChild(button);
}

void GUIHelperTest::onTestPressed(Object *sender, Control::EventType type)
{
	log("Pressed!");
}


#endif

#ifdef ENABLE_TDD
//
//  CCActionTest.m
//	TDD Framework 
//
//
#include "CCActionTest.h"
#include "TDDHelper.h"

void CCActionTest::setUp()
{
	log("TDD Setup is called");
	log("Please write somethings");
}


void CCActionTest::tearDown()
{
	log("TDD tearDown is called");
	log("Please do clean up here");
}

#pragma mark -
#pragma mark List of Sub Tests

void CCActionTest::setSubTest(Array *menuArray)
{
	SUBTEST(CCActionTest::testMove);
}

LabelTTF *CCActionTest::createTestLabel(const std::string &name)
{
	LabelTTF *label = LabelTTF::create(name, "Arial", 20);
	label->setPosition(Point(200, 200));
	addChild(label);
	return label;
}

#pragma mark -
#pragma mark Sub Test Definition
void CCActionTest::testMove(Object *sender)
{
	log("testMove");
	
	LabelTTF *label = createTestLabel("Hello");

	MoveTo *move = MoveTo::create(3, Point(300, 300));
	
	label->runAction(move);
	
	hideMenu();
}


#endif

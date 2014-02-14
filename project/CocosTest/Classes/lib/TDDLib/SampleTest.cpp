#ifdef ENABLE_TDD
//
//  SampleTest.cpp
//  Dg
//
//  Created by Ken Lee on 15/12/13.
//
//

#include "SampleTest.h"
#include "TDDHelper.h"

void TDDSample1::setUp()
{
	log("Test is setUp");
	
	Size size = TDDHelper::getScreenSize();
	Point top = Director::getInstance()->convertToGL(Point(0, 200));

	
	LabelTTF *label = LabelTTF::create("Sample Code 1", kDefaultFont, kDefaultFontSize);
	label->setPosition(Point(size.width/2, top.y - 40));
	addChild(label);

	int centerX = size.width / 2;
	Point pos = Point(centerX, top.y - 200);
	
	int fontsizeArray[] = {20, 30, 40};
	
	for(int i=0; i<3; i++) {
		int fontSize = fontsizeArray[i];
		
		String *str = String::createWithFormat("Font Size: %d", fontSize);
		
		LabelTTF *label = LabelTTF::create(str->getCString(), kDefaultFont, fontSize);
		label->setPosition(pos);
		addChild(label);
		
		pos.y -= fontSize * 1.5;
	}
	
}

void TDDSample1::tearDown()
{
	log("Test is tearDown (before onExit)");
}


void TDDSample1::setSubTest(Array *menuArray)
{
	SUBTEST(TDDSample1::test1);
	SUBTEST(TDDSample1::test2);
	SUBTEST(TDDSample1::test3);

}

#pragma mark -
#pragma mark Sub Test Definition
void TDDSample1::test1(Object *sender)
{
	log("hello this is test1");
}

void TDDSample1::test2(Object *sender)
{
	log("hello this is test2");
}


void TDDSample1::test3(Object *sender)
{
	log("hello this is test3");
}

#endif
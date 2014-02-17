#ifdef ENABLE_TDD
//
//  GUIHelperTest.h
//
//
#ifndef __TDD_GUIHelperTest__
#define __TDD_GUIHelperTest__

// Include Header

#include "TDDTest.h"

// Class Declaration 
class GUIHelperTest : public TDDTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void setSubTest(Array *menuArray);
	
private:
	void subTest(Object *sender);
	
	void onTestPressed(Object *sender, Control::EventType type);
}; 

#endif

#endif

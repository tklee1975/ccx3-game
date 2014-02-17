#ifdef ENABLE_TDD
//
//  CCActionTest.h
//
//
#ifndef __TDD_CCActionTest__
#define __TDD_CCActionTest__

// Include Header

#include "TDDTest.h"

// Class Declaration 
class CCActionTest : public TDDTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void setSubTest(Array *menuArray);
	
private:
	LabelTTF *createTestLabel(const std::string &name);
	void testMove(Object *sender);
}; 

#endif

#endif

#ifdef ENABLE_TDD
//
//  TDDMenuTest.h
//
//
#ifndef __TDD_TDDMenuTest__
#define __TDD_TDDMenuTest__

// Include Header

#include "TDDTest.h"

// Forward Declaration
class TDDMenu;

// Class Declaration 
class TDDMenuTest : public TDDTest
{
	virtual void setUp();
	virtual void tearDown();
	
private:
	void callback(Object * sender);
	
private:
	TDDMenu *mMenu;
	Array *mMenuArray;
}; 

#endif

#endif
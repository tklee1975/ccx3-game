#ifdef ENABLE_TDD
//
//  SampleTest.h
//  Dg
//
//  Created by Ken Lee on 15/12/13.
//
//

#ifndef __Dg__SampleTest__
#define __Dg__SampleTest__

#include <iostream>
#include "TDDTest.h"

class TDDSample1 : public TDDTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void setSubTest(Array *menuArray);
	
private:
	void test1(Object *sender);
	void test2(Object *sender);
	void test3(Object *sender);
};

#endif /* defined(__Dg__SampleTest__) */
#endif
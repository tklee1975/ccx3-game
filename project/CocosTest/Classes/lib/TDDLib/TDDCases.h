//
//  TDDDefine.h
//  Dg
//
//  Created by Ken Lee on 13/12/13.
//
//

#ifdef ENABLE_TDD
#ifndef Dg_TDDDefine_h
#define Dg_TDDDefine_h

#include "TDDTypes.h"
#include "TDDTest.h"		// contain the data structure 

// Add the Header here!
#include "SampleTest.h"
#include "CCActionTest.h"
#include "SpineTest.h"
#include "GUIHelperTest.h"

// MACRO
#define ADD_CASE(__ClassName__)					{#__ClassName__, []() { return new __ClassName__(); } }

// Define
TDDTestCase gTestArray[] =
{
	ADD_CASE(TDDTest),
	ADD_CASE(SpineTest),
	ADD_CASE(GUIHelperTest),
	ADD_CASE(CCActionTest),
	ADD_CASE(TDDSample1),
};

#endif
#endif
//
//  TDDTypes.h
//  Dg
//
//  Created by Ken Lee on 13/12/13.
//
//

#ifndef Dg_TDDTypes_h
#define Dg_TDDTypes_h
// C++ includes
#include <map>
#include <functional>
#include <string>

// TDD includes


enum TDDAlign
{
	eTDDTop				= 1,
	eTDDMiddle			= 2,
	eTDDBottom			= 3,

	eTDDLeft			= 1 << 2,
	eTDDCenter			= 2 << 2,
	eTDDRight			= 3 << 2,

	
	// Combined
//	eTDDTopLeft,
//	eTDDTopRight,
//	eTDDBottomLeft,
//	eTDDBottomRight,
};


#define kDefaultFont				"Arial"
#define kDefaultFontSize			20
#define kDefaultToolbarHeight		35
#define kDefaultMenuRowHeight		35

#endif

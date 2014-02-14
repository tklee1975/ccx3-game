//
//  TDDHelper.h
//  Dg
//
//  Created by Ken Lee on 13/12/13.
//
//

#ifndef __Dg__TDDHelper__
#define __Dg__TDDHelper__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "TDDTypes.h"
#include <string>
#include <vector>

USING_NS_CC;
USING_NS_CC_EXT;

using namespace std;

class TDDHelper
{
public:
	static Size getScreenSize();
	static Point getAlignPoint(float x, float y, TDDAlign halign, TDDAlign valign);
	
	static void showTests();
	static void addTestButton(Node *parent, cocos2d::Point pos);
	static Menu *createMenu(cocos2d::Point pos, const char *name, const ccMenuCallback& callback);
	static MenuItem *createMenuItem(const char *name, const ccMenuCallback& callback);
	static void scrollToTop(ScrollView *scrollView);
	static Point getCenter(Size &parentSize, Size &nodeSize);
	static EditBox *createEditBox(Node *parent, Point position, Size size);
	static void saveFilter(const char *pattern);
	static const char *getFilter();
};

#endif /* defined(__Dg__TDDHelper__) */

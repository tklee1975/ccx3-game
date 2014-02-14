//
//  TDDMenu.h
//  Dg
//
//  Created by Ken Lee on 16/12/13.
//
//

#ifndef __Dg__TDDMenu__
#define __Dg__TDDMenu__

#include <iostream>


#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;


class TDDMenu : public ScrollView
{
public:
	TDDMenu(Size size, Color4B color, float rowHeight);
	~TDDMenu();
	
	void setMenuItems(Array *itemArray);
	
	// private data
private:
	LayerColor *mMainLayer;
	Menu *mMenu;
	float mRowHeight;
//	Array *mMenuItemArray;
	
	// private method
private:
	void addMenuItems(Array *itemArray);
};



#endif /* defined(__Dg__TDDMenu__) */

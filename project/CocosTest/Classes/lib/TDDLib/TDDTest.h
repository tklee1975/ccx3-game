#ifdef ENABLE_TDD
//
//  TDDTest.h
//  Dg
//
//	Base Class of the Test Driven Unit Test
//
//  Created by Ken Lee on 13/12/13.
//
//

#ifndef __Dg__TDDTest__
#define __Dg__TDDTest__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "TDDTypes.h"

USING_NS_CC;
USING_NS_CC_EXT;

// Macro
#define SUBTEST(__Method__)	addSubTestMenu(menuArray, #__Method__, CC_CALLBACK_1(__Method__, this));

// Forward class declaration
class TDDMenu;

class TDDTest : public Scene
{
public:
	TDDTest(bool portrait = true, bool physics = false);
    virtual void onEnter();
	virtual void onExit();
	
    // virtual void runTest() = 0;		// must implemented

	
	
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual bool showStat();
	virtual void setSubTest(Array *menuArray);
	void addSubTestMenu(Array *menuArray, const char *name, const ccMenuCallback& callback);
	void hideMenu();
	void hideToolBar();
	void setMenuVisible(bool flag);
	void setToolBarOpacity(GLubyte value);

private:
	void setupGUI();
	void configTest();
	void resetConfig();
	void sampleTest(Object *sender);
	
	Menu *createBackMenu();
	Menu *createToggleMenu();
	
	void setupControlLayer();
	LayerColor *createToolBarLayer(bool hasMenu);
	TDDMenu *createTDDMenu();
	void toggleMenu(Object *sender);
	void toggleStat(Object *sender);
	
// private data
private:
	Layer *mControlLayer;	// Core control layer contains ToolBar & SubTest Menu
	LayerColor *mToolBarLayer;
	TDDMenu *mTDDMenu;
	bool mMenuVisible;
};

// C++ 11
#define CL(__className__) [](){ return new __className__();}


typedef struct {
	const char *name;
	std::function<TDDTest *()> callback;
} TDDTestCase;


#endif /* defined(__Dg__TDDTest__) */
#endif
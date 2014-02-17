//
//  CCBLayer.h
//  Dg
//
//  Created by Ken Lee on 19/12/13.
//
//

#ifndef __Dg__CCBLayer__
#define __Dg__CCBLayer__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
#include "cocosbuilder/CocosBuilder.h"
#include "PopupLayer.h"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace cocosbuilder;

#pragma mark -
#pragma mark Helper Macro

// Create the Loader
#define CREATE_LOADER(_ClassName_) \
class _ClassName_##Loader : public cocosbuilder::NodeLoader {		\
public:															\
CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(_ClassName_##Loader, loader);	\
protected:														\
CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(_ClassName_);			\
};


// MenuItem Selector
#define DECLARE_CCB_MENUITEM_SELECTOR \
virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::Object *pTarget, const char *pSelectorName);

#define DEFINE_CCB_MENUITEM_SELECTOR(_ClassName_) \
cocos2d::SEL_MenuHandler _ClassName_::onResolveCCBCCMenuItemSelector(cocos2d::Object *pTarget, const char *pSelectorName)

//virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::Object * pTarget, const char* pSelectorName) = 0;
//virtual cocos2d::SEL_CallFuncN onResolveCCBCCCallFuncSelector(cocos2d::Object * pTarget, const char* pSelectorName) { return NULL; };
//virtual cocos2d::extension::Control::Handler onResolveCCBCCControlSelector(cocos2d::Object * pTarget, const char* pSelectorName) = 0;


// Control Selector
#define DECLARE_CCB_CONTROL_SELECTOR \
virtual cocos2d::extension::Control::Handler onResolveCCBCCControlSelector(cocos2d::Object *pTarget, const char *pSelectorName);

#define DEFINE_CCB_CONTROL_SELECTOR(_ClassName_) \
cocos2d::extension::Control::Handler _ClassName_::onResolveCCBCCControlSelector(cocos2d::Object *pTarget, const char *pSelectorName)


// Variable
#define DECLARE_CCB_ASSIGN_MEMBER \
virtual bool onAssignCCBMemberVariable(cocos2d::Object *pTarget, const char *pMemberVariableName, cocos2d::Node *pNode);

#define DEFINE_CCB_ASSIGN_MEMBER(_ClassName_) \
bool _ClassName_::onAssignCCBMemberVariable(cocos2d::Object *pTarget, const char *pMemberVariableName, cocos2d::Node *pNode)


#pragma mark -
#pragma mark CCBLayer Definition
class CCBLayer
: public Layer
, public CCBSelectorResolver
, public CCBMemberVariableAssigner
, public NodeLoaderListener
{
public:
	// CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(CCBTestLayer, create);
	CCBLayer() {}
	virtual ~CCBLayer() {}
};


#pragma mark -
#pragma mark CCBLayerPopup Definition
class CCBPopupLayer
: public PopupLayer
, public CCBSelectorResolver
, public CCBMemberVariableAssigner
, public NodeLoaderListener
{
public:
	CCBPopupLayer() {}
	virtual ~CCBPopupLayer() {}
};



#endif /* defined(__Dg__CCBLayer__) */

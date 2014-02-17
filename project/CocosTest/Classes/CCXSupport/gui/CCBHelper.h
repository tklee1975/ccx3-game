//
//  CCBHelper.h
//  Dg
//
//  Created by Ken Lee on 19/12/13.
//
//

#ifndef __Dg__CCBHelper__
#define __Dg__CCBHelper__

#include <iostream>
#include "cocos2d.h"
#include "cocosbuilder/CocosBuilder.h"

USING_NS_CC;

// Macro

// Assume the Class Name define same in Code and CCB File
// Example: CREATE_CCBLAYER(MyCCBLayer, "MyCCBLayer", this)
#define CREATE_CCBLAYER(__class__, __ccbFile__, owner) \
(__class__ *) CCBHelper::createCCBLayer(__class__##Loader::loader(), #__class__, __ccbFile__, owner)


// Assume the Method Name define same in Code and CCB File
#define BIND_CCCONTROL_METHOD(__className__, __methodName__) \
CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, #__methodName__, __className__::__methodName__)

// Assume the Method Name define same in Code and CCB File
#define BIND_CCMENUITEM_METHOD(__className__, __methodName__) \
CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this,  #__methodName__, __className__::__methodName__)


// Assume the Variable Name define same in Code and CCB File
#define BIND_BUTTON(__varName__) \
CCB_MEMBERVARIABLEASSIGNER_GLUE(this, #__varName__, ControlButton *, __varName__)

#define BIND_NODE(__varName__) \
CCB_MEMBERVARIABLEASSIGNER_GLUE(this, #__varName__, Node *, __varName__)

#define BIND_LABEL_TTF(__varName__) \
CCB_MEMBERVARIABLEASSIGNER_GLUE(this, #__varName__, LabelTTF *, __varName__)

#define BIND_SPRITE(__varName__) \
CCB_MEMBERVARIABLEASSIGNER_GLUE(this, #__varName__, Sprite *, __varName__)

#define BIND_PARTICLE(__varName__) \
CCB_MEMBERVARIABLEASSIGNER_GLUE(this, #__varName__, ParticleSystemQuad *, __varName__)

#define BIND_LAYER_COLOR(__varName__) \
CCB_MEMBERVARIABLEASSIGNER_GLUE(this, #__varName__, LayerColor *, __varName__)

#define BIND_LAYER_GRADIENT(__varName__) \
CCB_MEMBERVARIABLEASSIGNER_GLUE(this, #__varName__, LayerGradient *, __varName__)


#define BIND_LAYER(__varName__) \
CCB_MEMBERVARIABLEASSIGNER_GLUE(this, #__varName__, Layer *, __varName__)


//
//
class CCBLayer;

class CCBHelper
{
public:
	static CCBLayer *createCCBLayer(cocosbuilder::NodeLoader * nodeLoader,
									const char *className,
									const char *ccbFileName, cocos2d::Object* pOwner = NULL);
		
	static Node *createSimpleCCBLayer(const char *ccbFileName, Object* pOwner = NULL);
};;

#endif /* defined(__Dg__CCBHelper__) */

//
//  CCBHelper.cpp
//  Dg
//
//  Created by Ken Lee on 19/12/13.
//
//

#include "CCBHelper.h"
#include "cocos2d.h"
#include "cocos-ext.h"
#include "cocosbuilder/CocosBuilder.h"

#include "CCBLayer.h"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace cocosbuilder;


CCBLayer *CCBHelper::createCCBLayer(cocosbuilder::NodeLoader * nodeLoader,
									const char *className,
									const char *ccbFileName,
									Object* pOwner)
{
	NodeLoaderLibrary * ccNodeLoaderLibrary = NodeLoaderLibrary::newDefaultNodeLoaderLibrary();
    ccNodeLoaderLibrary->registerNodeLoader(className, nodeLoader);
	
    /* Create an autorelease CCBReader. */
    cocosbuilder::CCBReader * ccbReader = new cocosbuilder::CCBReader(ccNodeLoaderLibrary);
    
    /* Read a ccbi file. */
    CCBLayer *layer = (CCBLayer *) ccbReader->readNodeGraphFromFile(ccbFileName, pOwner);
    
    ccbReader->release();
	
	return layer;
}

Node *CCBHelper::createSimpleCCBLayer(const char *ccbFileName, Object* pOwner)
{
	NodeLoaderLibrary *loaderLibrary = NodeLoaderLibrary::newDefaultNodeLoaderLibrary();

	CCBReader *reader = new CCBReader(loaderLibrary);	// library, memberAssigner, selectorResolver
	Node *node = reader->readNodeGraphFromFile(ccbFileName, pOwner);
	delete reader;
	
	return node;
}

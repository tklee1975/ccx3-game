#ifdef ENABLE_TDD
//
//  SpineTest.m
//	TDD Framework 
//
//
#include "SpineTest.h"
#include "TDDHelper.h"
#include "cocos-ext.h"

#include <vector>

#include "spine/spine.h"
#include "GUIHelper.h"

#define kTagSpinePlayer		10000

#define kTagButtonWalk		11001
#define kTagButtonJump		11002
#define kTagButtonHurt		11003
#define kTagButtonIdle		11004


USING_NS_CC_EXT;
using namespace spine;

void SpineTest::setUp()
{
	log("TDD Setup is called");
	log("Please write somethings");
	
	mAnime = NULL;
}


void SpineTest::tearDown()
{
	log("TDD tearDown is called");
	log("Please do clean up here");
}

#pragma mark -
#pragma mark List of Sub Tests

void SpineTest::setSubTest(Array *menuArray)
{
	SUBTEST(SpineTest::testSimple);
	SUBTEST(SpineTest::testChangeAnimation);
}

void SpineTest::changeAnime(Object *sender, Control::EventType type)
{
	if(mAnime == NULL) {
		log("mAnime is NULL");
		return;
	}
	
	//
	ControlButton *button = dynamic_cast<ControlButton *>(sender);
	if(button == NULL) {
		return;
	}
	
	//
	int tag = button->getTag();
	
	switch(tag) {
		case kTagButtonWalk:
		{
			log("walk");
			mAnime->setAnimation(0, "walk", true);
			break;
		}
			
		case kTagButtonJump:
		{
			log("jump");
			mAnime->setAnimation(0, "jump", true);
			break;
		}
			
		case kTagButtonHurt:
		{
			log("hurt");
			mAnime->setAnimation(0, "hurt", true);
			break;
		}
			
		case kTagButtonIdle:
		{
			log("idle");
			mAnime->setAnimation(0, "idle", true);
			break;
		}

	}
}

#pragma mark -
#pragma mark Sub Test Definition
void SpineTest::testSimple(Object *sender)
{
	log("testSimple");
	
	SkeletonAnimation *node = SkeletonAnimation::createWithFile("player.json", "player.atlas");
    node->setAnimation(0, "walk", true);
	
	node->setPosition(Point(200, 200));

	addChild(node);
}

void SpineTest::testChangeAnimation(Object *sender)
{
	log("testChangeAnimation");
	
	// Setting the Animation
	SkeletonAnimation *node = SkeletonAnimation::createWithFile("player.json", "player.atlas");
    node->setAnimation(0, "walk", true);
	node->setPosition(Point(200, 120));
	node->setTag(kTagSpinePlayer);
	addChild(node);
	mAnime = node;
	
	// Setting the buttons
	std::vector<Node *> nodeArray;
	ControlButton *button;
	
	button = GUIHelper::createButton("Walk", this, cccontrol_selector(SpineTest::changeAnime), Point(0, 0));
	button->setTag(kTagButtonWalk);
	nodeArray.push_back(button);
	
	button = GUIHelper::createButton("Jump", this, cccontrol_selector(SpineTest::changeAnime), Point(0, 0));
	button->setTag(kTagButtonJump);
	nodeArray.push_back(button);

	button = GUIHelper::createButton("Hurt", this, cccontrol_selector(SpineTest::changeAnime), Point(0, 0));
	button->setTag(kTagButtonHurt);
	nodeArray.push_back(button);

	button = GUIHelper::createButton("Idle", this, cccontrol_selector(SpineTest::changeAnime), Point(0, 0));
	button->setTag(kTagButtonIdle);
	nodeArray.push_back(button);

	GUIHelper::addNodesToParent(this, nodeArray, 0, 50, 480, 10);
	
	
	// hide the menu
	hideMenu();
}


#endif

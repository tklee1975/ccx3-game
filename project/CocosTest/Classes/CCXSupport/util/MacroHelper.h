//
//  MacroHelper.h
//  Dg
//
//  Created by Ken Lee on 26/12/13.
//
//

#ifndef Dg_MacroHelper_h
#define Dg_MacroHelper_h
#include "cocos2d.h"

#define IS_ANDROID	(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#define IS_IOS		(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#define IS_WIN		(CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)

#define CCOBJECT_VECTOR_RELEASE(_vector_)		\
for(size_t i=0; i<_vector_.size(); i++) {		\
if(_vector_[i]) {								\
_vector_[i]->release();							\
}												\
}												\
_vector_.clear();

#define SET_CONTAIN(_set_, _value_)			(_set_.find(_value_) != _set_.end())
#define SET_NOT_CONTAIN(_set_, _value_)		(_set_.find(_value_) == _set_.end())

#endif

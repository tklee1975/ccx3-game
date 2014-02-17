//
//  Array2D.h
//  Dg
//
//  Created by Ken Lee on 26/12/13.
//
//

#ifndef __Dg__Array2D__
#define __Dg__Array2D__

#include <iostream>
#include <string>
#include "cocos2d.h"

USING_NS_CC;

class Array2D : Object
{
public:
	Array2D(int col, int row, int intValue=0);
	virtual ~Array2D();
	
	void set(int x, int y, int value);
	int get(int x, int y);
	
	std::string toString(bool isReverse=false);
	
private:
	int mRow;
	int mCol;
	int mSize;
	int *mData;
	
};

#endif /* defined(__Dg__Array2D__) */

//
//  Array2D.cpp
//  Dg
//
//  Created by Ken Lee on 26/12/13.
//
//

#include "Array2D.h"

#define INDEX(_col_, _row_, _numCol_)	(_row_ * _numCol_ + _col_)

Array2D::Array2D(int col, int row, int initValue)
: Object()
{
	mRow = row;
	mCol = col;
	
	mSize = mRow * mCol;
	mData = (int *) malloc(mSize * sizeof(int));
	for(int i=0; i<mSize; i++) {
		mData[i] = initValue;
	}
	
	
}

Array2D::~Array2D()
{
	delete mData;
	mData = NULL;
}


void Array2D::set(int x, int y, int value)
{
	int idx = INDEX(x, y, mCol);
	if(idx >= mSize) {
		//log("Array2D::set invalid input. idx=%d while size=%d", idx, mSize);
		return;
	}
	
	mData[idx] = value;
}

int Array2D::get(int x, int y)
{
	int idx = INDEX(x, y, mCol);
	if(idx >= mSize) {
		log("Array2D::get invalid input. idx=%d while size=%d", idx, mSize);
		return 0;
	}
	
	return mData[idx];
}


std::string Array2D::toString(bool isReverse)
{
	
	
	char temp[10];
	
	std::vector<std::string> strList;
	
	for(int r=0; r<mRow; r++){
		std::string line("");
		
		for(int c=0; c<mCol; c++){
			int idx = r * mCol + c;
			
			int value = mData[idx];
			
			sprintf(temp, "%4d", value);

			line.append(temp);
		}
		
		strList.push_back(line);
	}
	
	std::string result;
	
	if(isReverse) {
		for(int i=strList.size()-1; i>=0; i--){
			result.append(strList[i]);
			result.append("\n");
		}
	} else {
		for(int i=0; i<strList.size(); i++) {
			result.append(strList[i]);
			result.append("\n");
		}
		
	}
	
	
	return result;
}
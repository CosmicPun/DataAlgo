#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "queue.h"

template <typename T>
void CP::queue<T>::insert_shuffle(std::vector<T> items, size_t pos){
	std::vector<T> v;
	size_t idx=0;
	for(int i=0;i<mSize;i++){
		if(i>=pos){
			if(idx<items.size()){
				v.push_back(items[idx]);
				idx++;
			}
		}
		v.push_back(mData[(mFront+i)%mCap]);
	}
	while(idx<items.size()){
		v.push_back(items[idx]);
		idx++;
	}
	
	ensureCapacity(mSize + items.size());
	size_t st = mFront;
	for(auto x:v){
		mData[st%mCap] = x;
		st++;
	}
	mSize = v.size();
}

#endif

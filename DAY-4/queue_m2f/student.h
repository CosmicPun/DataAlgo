#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "queue.h"
#include <algorithm>
#include <iostream>

template <typename T>
void CP::queue<T>::move_to_front(size_t pos) {
    if(pos==0)return;

    for(int i=pos;i>0;i--){
        size_t idx = (mFront+i)%mCap;
        T tmp = mData[idx];
        mData[idx] = mData[(idx-1)%mCap];
        mData[(idx-1)%mCap] = tmp;
    }
}


#endif
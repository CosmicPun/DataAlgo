#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <cassert>

template <typename T>
void CP::queue<T>::reverse(int a,int b) {
    for(size_t i=0;i<(b-a+1)/2;i++){
        size_t st = (mfront+a+i)%mCap;
        size_t ed = (mfront+b-i)%mCap;
        T tmp = mData[st];
        mData[st] = mData[ed];
        mData[ed] = tmp;
    }
}

#endif

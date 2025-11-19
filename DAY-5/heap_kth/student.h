#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "priority_queue.h"

template <typename T,typename Comp >
T CP::priority_queue<T,Comp>::get_kth(size_t k) const {
  std::vector<T> tmp;
  size_t size;
  if(mSize > 10)size = 10;
  else size = mSize;
  for(size_t i=0;i<size;i++){
    tmp.push_back(mData[i]);
  }
  std::sort(tmp.begin(), tmp.end(), mLess);
  return tmp[tmp.size()-k];
}

#endif

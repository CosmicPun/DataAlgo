#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <set>


template <typename T>
void CP::vector<T>::uniq() {
  T *arr = new T[mSize]();
  size_t idx = 0;
  std::set<T> s;
  for(size_t i=0;i<mSize;i++){
    if(s.find(mData[i])==s.end()){
      s.insert(mData[i]);
      arr[idx] = mData[i];
      idx++;
    }
  }
  delete [] mData;
  mData = arr;
  mSize = idx;
}

#endif

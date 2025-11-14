#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
void CP::vector<T>::insert_many(CP::vector<std::pair<int,T>> data) {
  std::sort(data.begin(), data.end());
  
  size_t new_size = mSize + data.size();
  ensureCapacity(new_size);
  
  int data_idx = data.size() - 1;
  int old_idx = mSize - 1;
  int new_idx = new_size - 1;
  
  while(data_idx >= 0 || old_idx >= 0) {
    if(data_idx >= 0 && (old_idx < 0 || old_idx < data[data_idx].first)) {
      mData[new_idx] = data[data_idx].second;
      data_idx--;
    } else {
      mData[new_idx] = mData[old_idx];
      old_idx--;
    }
    new_idx--;
  }
  
  mSize = new_size;
}

#endif
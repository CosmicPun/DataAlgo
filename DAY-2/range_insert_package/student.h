#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::insert(iterator position,iterator first,iterator last) {
  size_t pos = position - begin();
  size_t length = last - first;
  if (length == 0) return;
  T *tmp = new T[length];
  for (size_t i = 0; i < length; ++i) {
    tmp[i] = *(first + i);
  }
  ensureCapacity(mSize + length);

  for (size_t i = mSize; i > pos; --i) mData[i + length - 1] = mData[i - 1];
  for (size_t i = 0; i < length; ++i) mData[pos + i] = tmp[i];

  mSize += length;
  delete [] tmp;
}

#endif

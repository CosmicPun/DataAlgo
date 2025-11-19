#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <algorithm>

template <typename T>
void CP::list<T>::merge(CP::list<CP::list<T>> &ls) {
  for(auto it=ls.begin(); it!=ls.end(); it++){
    list<T> &child = *it;
    if(child.empty())continue;
    node* main = mHeader;
    node* child_st = child.mHeader->next;
    node* child_ed = child.mHeader->prev;
    main->prev->next = child_st;
    child_st->prev = main->prev;
    child_ed->next = mHeader;
    mHeader->prev = child_ed;
    mSize += child.mSize;
    child.mHeader->next = child.mHeader;
    child.mHeader->prev = child.mHeader;
    child.mSize = 0;
  }
  return;
}

#endif
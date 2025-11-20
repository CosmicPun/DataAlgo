#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>


template <typename KeyT,
          typename MappedT,
          typename CompareT>
size_t CP::map_bst<KeyT,MappedT,CompareT>::leaves_count(node* n) {
  if(n == NULL)return size_t(0);
  if(n->left == NULL && n->right == NULL)return size_t(1);
  return leaves_count(n->left) + leaves_count(n->right);
}


template <typename KeyT,
          typename MappedT,
          typename CompareT>
size_t CP::map_bst<KeyT,MappedT,CompareT>::leaves_count() {
  return leaves_count(mRoot);
}


#endif

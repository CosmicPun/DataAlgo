#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos) {
  size_t count = 0;
  for(auto& x:pos){
    auto it = begin()+x-count;
    erase(it);
    count++;
  }
}

#endif

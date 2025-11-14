#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::block_swap(iterator a, iterator b, size_t m) {
  if(m<=0)return false;
  if(a>b){
    iterator tmp = a;
    a = b;
    b = tmp;
  }
  else if(a==b)return false;

  if (a < begin() || b < begin()) return false;
  if (a + m > end() || b + m > end()) return false;
  
  if (!(a + m <= b || b + m <= a)) return false;
  
  for(size_t i=0;i<m;i++){
    T tmp = *(a+i);
    *(a+i) = *(b+i);
    *(b+i) = tmp;
  }
  return true;
}

#endif

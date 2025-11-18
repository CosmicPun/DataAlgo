#ifndef __APLUSB_H_
#define __APLUSB_H_
#include <vector>

std::vector<int> a,b;

void initialize(std::vector<int> A, std::vector<int> B) {
  a = A;
  b = B;
  return;
}

int answer_question(int i, int j) {
  return a[i] + b[j];
}

#endif
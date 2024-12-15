#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <cassert>

template <typename T>
void CP::queue<T>::reverse(int a,int b) {
  //your code here
  assert(a >= 0 && b >= a && b < mSize);
  while(a<b){
    std::swap(mData[(mFront+a)%mCap],mData[(mFront+b)%mCap]);
    a++;
    b--;
  }
}

#endif

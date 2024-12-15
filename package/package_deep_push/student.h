#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::stack<T>::deep_push(size_t pos, const T& value) {
  T* snew = new T[mSize + 1];

  for (size_t i = 0; i < mSize - pos; i++) {
    snew[i] = mData[i];
  }

  snew[mSize - pos] = value;

  for (size_t i = mSize - pos; i < mSize; i++) {
    snew[i + 1] = mData[i];
  }

  delete[] mData;
  mData = snew;
  mSize += 1;
  mCap = mSize;
}

#endif

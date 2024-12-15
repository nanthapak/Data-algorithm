#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos) {
  //write your code here
  T *vec = new T[mSize-pos.size()];
  int offset=0;
  auto track = pos.begin();
  for(int i=0;i<mSize;i++){
    if(track!=pos.end()&&i==*track){
      track++;
    }
    else{
      vec[offset]=mData[i];
      offset++;
    }
  }
  delete[] mData;
  mData=vec;
  mSize=mSize-pos.size();
  mCap=mSize;
}

#endif

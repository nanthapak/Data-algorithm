void replace(const T& x, list<T>& y) {
  //write your code here
  auto itr=begin();
  while(itr!=end()){
    if(*itr==x){
        for(auto &x:y) insert(itr,x);
        auto temp=itr;
        temp++;
        erase(itr);
        itr=temp;
    }
    else itr++;
  }
}

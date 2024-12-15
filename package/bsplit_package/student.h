#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename KeyT,
          typename MappedT,
          typename CompareT >


CP::map_bst<KeyT,MappedT,CompareT> CP::map_bst<KeyT,MappedT,CompareT>::split(KeyT val) {
  //your code here
  CP::map_bst<KeyT,MappedT,CompareT> result;
  node *tmp=mRoot;
  node *res=result.mRoot;
  while(true){
    if(tmp->data<val){
      tmp=tmp->right;
    }
    else{
      
    }
  }
  return result;
}


#endif

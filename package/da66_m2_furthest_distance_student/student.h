#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "map_bst.h"
using namespace std;
template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::my_recur(node* n, int &aux){
	// You MAY use this function
	if(!n) return 0;

    int lh=my_recur(n->left,aux);
    int rh=my_recur(n->right,aux);

    aux=max(aux,lh+rh);
    return max(lh,rh)+1;
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::furthest_distance() {
	// write your code here
	if(!mRoot) return -1;
    if((!mRoot->left)&&(!mRoot->right)) return 0;
    int aux=0;
    my_recur(mRoot,aux);
    return aux ;
}

#endif

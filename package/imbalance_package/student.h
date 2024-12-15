// Your code here

int compute(node* n,KeyT& ans,int &maxImb){
    if(!n) return -1;
    int rh=compute(n->right,ans,maxImb);
    int lh=compute(n->left,ans,maxImb);
    int h=1+ ((rh>lh)? rh:lh);
    int temp=rh-lh;
    if(temp<0) temp=-temp;
    if(temp>maxImb){
        maxImb=temp;
        ans=n->data.first;
    }
    else{
        if((imb==maxImb)&&(mLess(n->data.first,ans))){
            ans=n->data.first;
        }
    }
    return h;

}

KeyT getValueOfMostImbalanceNode() {
    // Your code here
    int maxImb=0;
    KeyT ans=mRoot->data.first;
    compute(mRoot,ans,maxImb);
    return ans; 
}

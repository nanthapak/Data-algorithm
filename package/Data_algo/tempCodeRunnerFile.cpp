#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

void checkzuma(list<int> &lst,list<int>::iterator &it,int v){


    auto lhs=it;
    int count=0;
    while(lhs!=lst.end()&&*lhs==v){
        lhs--;
        count++;
    }
    auto rhs=it;
    rhs++;
    while(rhs!=lst.end()&&*rhs==v){
        count++;
        rhs++;
    }
    lhs++;
    if(count>=3){
        lst.erase(lhs,rhs);
        lhs--;
        checkzuma(lst,lhs,*lhs);
    }
    else return;
}

int main(){
    int n,k,v;
    cin>>n>>k>>v;
    list<int> lst;
    for(int i=0;i<n;i++){
        int inp;
        cin>>inp;
        lst.push_back(inp);
    }
    auto it=lst.begin();
    for(int i=0;i<k;i++){
        it++;
    }
    lst.insert(it,v);
    --it;

    checkzuma(lst,it,v);
    for(auto x:lst){
        cout<<x<<" ";
    }
}
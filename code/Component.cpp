#include <iostream>
#include <vector>
#include<climits>
#include<algorithm>
#include<set>
using namespace std;
int findparent(vector<int> &parent,int x){
    if(parent[x]!=x) 
        parent[x]=findparent(parent,parent[x]);
    return parent[x];
}
void unionset(vector<int> &parent,int x,int y){
    int rootx=findparent(parent,x);
    int rooty=findparent(parent,y);
    if(rootx!=rooty)
        parent[rootx]=rooty;
}
int main(){
    int e,v,k;
    cin>>v>>e;
    vector<int> parent(v+1);
    for(int i=0;i<v+1;i++) parent[i]=i;
    set<int> s;
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        if(findparent(parent,x)!=findparent(parent,y)){
            unionset(parent,x,y);
        }
    }
    int sum=0;
    for(int i=1;i<=v;i++){
        s.insert(findparent(parent,parent[i]));
    }
    // cout<<endl;
    // for(auto &x:parent) cout<<x<<" ";
    // cout<<endl;
    cout<<s.size();
}
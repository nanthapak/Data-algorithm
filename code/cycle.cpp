#include <iostream>
#include <vector>
#include<climits>
#include<algorithm>
using namespace std;

int findparent(vector<int> &parent,int node){
    if(parent[node]==-1) return node;
    parent[node]= findparent(parent,parent[node]);
    return parent[node];
}
void unionset(vector<int> &parent,int x,int y){
    int rootx=findparent(parent,x);
    int rooty=findparent(parent,y);
    if(rootx!=rooty)
        parent[rootx]=rooty;
}


int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,e;
        cin>>n>>e;
        bool pass=false;
        vector<int> parent(n,-1);
        if(e==0){
            cout<<"NO"<<endl;
            continue;
        }
        else{
            int a,b;
            for(int j=0;j<e;j++){
                cin>>a>>b;
                if(findparent(parent,a)==findparent(parent,b)){
                    pass=true;
                }
                else{
                    unionset(parent,a,b);
                }
            }
        }
        if(pass) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
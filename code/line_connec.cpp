#include <iostream>
#include <vector>
#include<climits>
#include<algorithm>
#include<set>
using namespace std;

int findparent(vector<int> &parent,int x){
    if(parent[x]==x) return x;
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
    int e,v;
    cin>>v>>e;
    vector<vector<int>> G(v);
    vector<int> parent(v);
    for(int i=0;i<v;i++) parent[i]=i;
    if(e==0){
        cout<<v;
        return 0;
    }
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
        int roota=findparent(parent,a);
        int rootb=findparent(parent,b);
        if(roota!=rootb){
            unionset(parent,a,b);
        }
    }
    set<int> s;
    int count=0;
    for(int i=0;i<v;i++){
        s.insert(findparent(parent,i));
    }

    for(auto &x:s){
        bool pass=false;
        int countone=0;
        int countnode=0;
        int counttwo =0;
        for(int i=0;i<v;i++){
            if(parent[i]==x){
                countnode++;
                if(G[x].empty()){
                    pass=true;
                    break;
                }
                if(G[i].size()==2){
                    counttwo++;
                }
                if(G[i].size()==1) countone++;
            }
        }
        if(pass||(countone==2&&counttwo==countnode-2)) count++;
    }


    cout<<count;
}
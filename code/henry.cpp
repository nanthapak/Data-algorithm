#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<set>
#include<algorithm>
#include<map>
using namespace std;

int findparent(vector<int> &parent,int x){
    if(parent[x]==-1) return x;
    parent[x]=findparent(parent,parent[x]);
    return parent[x];
}
void unionset(vector<int> &heigth,vector<int>&parent,int x,int y){
    int rootx=findparent(parent,x);
    int rooty=findparent(parent,y);
    if(rootx!=rooty){
        if(heigth[rootx]>heigth[rooty]){
            parent[rooty]=rootx;
            heigth[rootx]=heigth[rootx]+heigth[rooty];
        }
        else{
            parent[rootx]=rooty;
            heigth[rooty]=heigth[rootx]+heigth[rooty];
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,pair<int,int>>> G;
    for(int i=1;i<=m;i++){
        int c,a,b;
        cin>>c>>a>>b;
        G.push_back({c,{a,b}});
    }
    sort(G.begin(),G.end());
    vector<int> parent(n+1,-1);
    vector<int> heigth(n+1,1);
    int sum=0;
    for(auto &x:G){
        int u=x.second.first;
        int v=x.second.second;
        if(findparent(parent,u)!=findparent(parent,v)){
            sum+=x.first;
            unionset(heigth,parent,u,v);
        }
    }
    cout<<sum;
}
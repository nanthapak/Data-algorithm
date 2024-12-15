#include <iostream>
#include <vector>
#include<climits>
#include<algorithm>
#include<set>
using namespace std;

void dfs(int now,vector<vector<int>> &ADJ,vector<int> &visited,int k){
    visited[now]=1;
    if(k>0)
        for(auto &x:ADJ[now]){
            dfs(x,ADJ,visited,k-1);
        }
}

int main(){
    int e,v,k;
    cin>>v>>e>>k;
    vector<vector<int>> ADJ(v);
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        ADJ[x].push_back(y);
        ADJ[y].push_back(x);
    }
    int maxi=0;
    for(int i=0;i<v;i++){
        int count=0;
        vector<int> visited(v,-1);
        dfs(i,ADJ,visited,k);
        for(auto &x:visited){
            if(x==1) count++;
        }
        maxi=max(count,maxi);
    }
    cout<<maxi;
}
#include <iostream>
#include <vector>
#include<climits>
#include<algorithm>
#include<set>
using namespace std;
int ans=0;
bool found=false;
void dfs(vector<vector<int>> &ADJ,vector<bool> &visited,vector<int> &depth,int now,int dep,int parent){
    visited[now]=true;
    depth[now]=dep;
    for(auto &x:ADJ[now]){
        if(visited[x]==false){
            dfs(ADJ,visited,depth,x,dep+1,now);
        }
        else if(visited[x]==true&&x!=parent&&!found){
            ans=dep-depth[x]+1;
            found=true;
            return;
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<bool> visited(n,false);
    vector<int> depth(n,0);
    vector<vector<int>> ADJ(n);
    int maxi=0;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        ADJ[a].push_back(b);
        ADJ[b].push_back(a);
    }
    dfs(ADJ,visited,depth,0,0,-1);
    cout<<ans;
}
#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<set>
#include<algorithm>
#include<map>
using namespace std;

int main(){
    //prim
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> infected(k);
    vector<int> w(n);
    vector<vector<int>> adj(n);
    for(int i=0;i<k;i++){
        cin>>infected[i];
    }
    for(int i=0;i<n;i++){
        cin>>w[i];
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> dist(n,INT_MAX);
    vector<bool> visited(n,false);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(auto &start:infected){
        pq.push({w[start],start});
        dist[start]=w[start];
    }
    int maxi=0;
    while(!pq.empty()){
        auto [T,n]=pq.top();
        pq.pop();
        for(auto &x:adj[n]){
            if(dist[x]>w[x]+T&&!visited[x]){
                dist[x]=w[x]+T;
                maxi=max(maxi,dist[x]);
                visited[x]=true;
                pq.emplace(dist[x],x);
            }
        }
    }
    //for(auto &x:dist) cout<<x<<" ";
    cout<<maxi;
}
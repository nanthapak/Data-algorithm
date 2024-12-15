#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<set>
#include<algorithm>
#include<map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<int> in(n);
    vector<int> out(n);
    for(int i=0;i<n;i++){
        cin>>in[i];
    }
    for(int i=0;i<n;i++){
        cin>>out[i];
    }
    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    vector<int> dist(n,999999);
    dist[0]=0;
    priority_queue<pair<int,int>> pq;
    pq.push({0,0});
    while(!pq.empty()){
        auto [T,u]=pq.top();
        pq.pop();
        for(auto &x:adj[u]){
            if(dist[x]>out[u]+in[x]+T){
                dist[x]=out[u]+in[x]+T;
                pq.emplace(dist[x],x);
            }
        }

    }
    for(auto &x:dist){
        if(x==999999){
            cout<<-1<<" ";
        }
        else{
            cout<<x<<" ";
        }
    }

}
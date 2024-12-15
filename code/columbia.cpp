#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<queue>
using namespace std;
int main(){
    int r,c;
    cin>>r>>c;
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    vector<vector<int>> fee(r,vector<int>(c));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>fee[i][j];
        }
    }
    vector<vector<int>> dist(r,vector<int>(c,INT_MAX));
    vector<vector<bool>> visit(r,vector<bool>(c,false));
    priority_queue<pair<int, pair<int, int>>, 
                    vector<pair<int, pair<int, int>>>, 
                    greater<pair<int, pair<int, int>>>> pq;

    pq.push({0,{0,0}});
    dist[0][0]=0;
    while(!pq.empty()){
        auto [T,p]=pq.top();
        int a=p.first;
        int b=p.second;
        pq.pop();
        for(auto &[i,j]:directions){
            int nx=a+i;
            int ny=b+j;
            if(nx>=0&&ny>=0&&nx<r&&ny<c&&!visit[nx][ny]){
                dist[nx][ny]=min(dist[nx][ny],T+fee[nx][ny]);
                pq.push({dist[nx][ny],{nx,ny}});
                visit[nx][ny]=true;
            }
        }
    }
    for(auto &x:dist){
        for(auto &y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }

}
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int r,c,t,x;
    cin>>r>>c>>t;
    queue<pair<int,int>> q;
    vector<vector<int>> table(r,vector<int>(c));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>x;
            table[i][j]=x;
            if(x==1) q.push({i,j});
        }
    }
    int count=q.size();
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int batch=0;
    int currday=q.size();
    int nextday=0;
    while(!q.empty()){
        if(currday==0){
            currday=nextday;
            nextday=0;
            batch++;
        }
        if(batch==t) break;
        currday--;
        int i=q.front().first;
        int j=q.front().second;
        q.pop();
        for (auto [di, dj] : directions) {
            int ni = i + di, nj = j + dj;
            if (ni >= 0 && ni < r && nj >= 0 && nj < c && !table[ni][nj]) {
                table[ni][nj]=1;
                count++;
                q.push({ni, nj});
                nextday++;
            }
        }
    }
    cout<<count;
}

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int r,c;
    cin>>r>>c;
    vector<pair<int,int>> vec={{1,0},{-1,0},{0,1},{0,-1}};
    vector<vector<int>> table(r,vector<int>(c));
    vector<pair<int,int>> start;
    queue<pair<int,int>> q;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>table[i][j];
            if(table[i][j]==2) q.push({i,j});
        }
    }



        vector<vector<bool>> visited(r,vector<bool>(c,false));
        int dist=0;
        bool pass=false;
        while(!q.empty()){
            if(pass) break;
            int temp=q.size();
            while(temp--)
            {auto [a,b]=q.front();
            q.pop();
   
            if(table[a][b]==1){
                pass=true;
                break;
            }
            for(auto &y:vec){
                int newi=a+y.first;
                int newj=b+y.second;
                if(newi>=0&&newi<r&&newj>=0&&newj<c&&!visited[newi][newj]&&table[newi][newj]!=3){
                    q.push({newi,newj});
                    visited[newi][newj]=true;
                }
            }}
            dist++;

        }


    cout<<dist; 
}
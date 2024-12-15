#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int r, c;
    cin >> r >> c;
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    vector<vector<int>> table(r, vector<int>(c));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            int a;
            cin>>a;
            table[i][j]=a;     
        }
    }
        int maxi=0;

        int dist=0;
        queue<pair<int,int>> q;
        q.push({0,0});
        bool pass=false;
        vector<vector<bool>> visited(r,vector<bool>(c,false));
        visited[0][0]=true;
        while(!q.empty()){
            int temp=q.size();
            while(temp--){
                auto[i,j]=q.front();
                q.pop();
                for(auto &[x,y]:directions){
                    int ni=i+x;
                    int nj=j+y;
                    if(ni>=0&&nj>=0&&ni<r&&nj<c&table[ni][nj]!=0&&!visited[ni][nj]){
                        if(table[ni][nj]==2){
                            maxi+=(dist+1);
                            table[i][j]=1;
                        }
                        visited[ni][nj]=true;
                        q.push({ni,nj});
    
                    }
                }
            }
            dist++;
        }

        cout<<maxi*2;
    
}

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<int> heigth;
int findparent(vector<int> &parent,int x){
    if(parent[x]==-1) return x;
    parent[x]=findparent(parent,parent[x]);
    return parent[x];
}
void unionset(vector<int> &heigth,vector<int> &parent,int x,int y){
    int rootx=findparent(parent,x);
    int rooty=findparent(parent,y);
    if (rootx != rooty) {
        if (heigth[rootx] > heigth[rooty]) {
            parent[rooty] = rootx;
            heigth[rootx] += heigth[rooty];
        } else {
            parent[rootx] = rooty;
            heigth[rooty] += heigth[rootx];
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int> heigth(n,1);
    vector<int> parent(n,-1);
    vector<pair<int,pair<int,int>>> connect;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            int num;
            cin>>num;
            connect.push_back({num,{i,j+i+1}});
        }
    }
    int ans=0;
    sort(connect.begin(),connect.end());
    for(auto &x:connect){
        if(findparent(parent,x.second.second)!=findparent(parent,x.second.first)){
            ans+=x.first;
            unionset(heigth,parent,x.second.second,x.second.first);
        }
    }
    cout<<ans;
}
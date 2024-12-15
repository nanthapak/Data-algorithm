#include <iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int bino(int n,int r,vector<vector<int>> &vec){
    if(r==n) return 1;
    if(r==0) return 1;

    if(vec[n][r]!=-1) return vec[n][r];

    int result=bino(n-1,r,vec)+bino(n-1,r-1,vec);
    vec[n][r]=result;
    return result;
}

int main(){
    int n,r;
    cin>>n>>r;
    vector<vector<int>> vec(n+1,vector<int> (r+1,-1));
    cout<<bino(n,r,vec);
}
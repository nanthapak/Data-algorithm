#include<iostream>
#include<set>
#include<vector>
#include<unordered_map>
using namespace std;

void genqr(int n,int m,vector<int> &sol,int now,int count){
    if(count>n) return;
    if(now<m){
        sol[now]=0;
        genqr(n,m,sol,now+1,count);
        sol[now]=1;
        genqr(n,m,sol,now+1,count+1);
    }
    else{
        if(count==n){
            for(auto x:sol) cout<<x;
            cout<<endl;
        }
        
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> sol(m);
    int now=0;
    int count=0;
    genqr(n,m,sol,now,count);
}
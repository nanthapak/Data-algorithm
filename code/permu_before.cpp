#include<iostream>
#include<set>
#include<vector>
#include<unordered_map>
using namespace std;
vector<pair<int,int>> vec;
void recur(int n,vector<int> &sol,int len,vector<bool> &used){
    if(len<n){
        for(int i=0;i<n;i++){
            if(used[i]==false){
                for(auto x:vec){
                    if(x.first==i&&used[x.second]==true){
                        return;
                    }
                }
                used[i]=true;
                sol[len]=i;
                recur(n,sol,len+1,used);
                used[i]=false;
            }
        }
    }
    else{
        for(auto &x:sol) cout<<x<<" ";
        cout<<endl;
    }
}


int main(){
    int n,m;
    set<pair<int,int>> s;
    cin>>n>>m;
    vector<int> sol(n);
    vector<bool> used(n,false);
    for(int i=0;i<m;i++){
        int p,q;
        cin>>p>>q;
        vec.push_back({p,q});
    }
    int len=0;
    recur(n,sol,len,used);
}
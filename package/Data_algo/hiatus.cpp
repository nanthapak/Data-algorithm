#include<vector>
#include<map>
#include<cmath>
#include<iostream>
#include<set>
using namespace std;

int main(){
    int n,m,a,b;
    set<pair<int,int>> sut;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        sut.insert(make_pair(a,b));
    }
    for(int i=0;i<m;i++){
        cin>>a>>b;
        auto it = sut.lower_bound(make_pair(a,b));
        if(it->first==a&&it->second==b){
            cout<<"0 0 ";
        }
        else if(it==sut.begin()) cout<<"-1 -1 ";
        else{
            it--;
            cout<<it->first<<" "<<it->second<<" ";
        }
    }
}
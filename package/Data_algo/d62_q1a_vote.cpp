#include<iostream>
#include<set>
#include<vector>
using namespace std;

int main(){
    int n,k;
    multiset<string> sut;
    set<string> sit;
    multiset<int> sat;
    vector<int> ans;
    string s;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>s;
        sut.insert(s);
        sit.insert(s);
    }
    for(auto x:sit){
        sat.insert(sut.count(x));
    }
    for(auto x:sat){
        ans.push_back(x);
    }
    if(k>=ans.size()) cout<<ans[0];
    else{
    cout<<ans[ans.size()-k];}

}
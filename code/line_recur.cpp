#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<set>
#include<algorithm>
#include<map>
using namespace std;
map<int,int> memo;
int R(vector<int> &a,vector<int> &c,int n,int k){
    if(n<k) return a[n];
    if(memo.find(n)!=memo.end()) return memo[n];
    int count=0;
    for(int i=1;i<=k;i++){
        count+=((c[i]%32717)*(R(a,c,n-i,k)%32717))%32717;
    }
    memo[n]=count%32717;
    return memo[n];
}

int main(){
    int k,n;
    cin>>k>>n;
    vector<int> ak(k);
    vector<int> ck(k+1);
    for(int i=1;i<=k;i++){
        cin>>ck[i];
    }
    for(int i=0;i<k;i++){
        cin>>ak[i];
    }
    cout<<R(ak,ck,n,k);
}
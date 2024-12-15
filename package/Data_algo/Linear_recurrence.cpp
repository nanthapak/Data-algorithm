#include<iostream>
#include<cmath>
#include<vector>
#include<climits>
#include<map>
using namespace std;
vector<long> c;
vector<long> a;
long k,n,ck,ak;
map<long,long> memo;
long linear(long n){
    if(n<k) return a[n];
    if(memo.find(n)!=memo.end()) return memo[n];
    long sum=0;
    for(int i=0;i<k;i++){
        sum+=((c[i]%32717)*(linear(n-i-1)%32717))%32717;
    } 
    memo[n]= sum%32717; 
    return memo[n];
}

int main(){
    cin>>k>>n;
    for(int i=0;i<k;i++){
        cin>>ck;
        c.push_back(ck);//1-k
    }
    for(int i=0;i<k;i++){
        cin>>ak;
        a.push_back(ak);//0-k-1
    }
    cout<<linear(n);
}
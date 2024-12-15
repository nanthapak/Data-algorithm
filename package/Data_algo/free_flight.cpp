#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include <climits>
map<long,long> Min,Mout,memo;
vector<pair<long,long>> path;

void checkpath(long &sum,long endpoint,long &minSum){
    if(endpoint==0){
        minSum = min(minSum, sum);
        return;
    }
    //if(memo.find(endpoint)!=memo.end()) {minSum=memo[endpoint]; return;}
    bool checkpass=false;
    for(auto x:path){
        if(x.second==endpoint){
            sum+=Min[endpoint]+Mout[x.first];
            if(memo.find(x.first)!=memo.end()) {minSum=memo[x.first]; return;}
            checkpath(sum,x.first,minSum);
            sum=sum-(Min[endpoint]+Mout[x.first]);
            checkpass=true;
        }
    }
    if(!checkpass){
        minSum=-1;
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long n,m,price;
    cin>>n>>m;
    for(long i=0;i<n;i++){
        cin>>price; 
        Min[i]=price;
    }
    for(long i=0;i<n;i++){
        cin>>price;
        Mout[i]=price;
    }
    long fst,snd;
    for(long i=0;i<m;i++){
        cin>>fst>>snd;
        path.push_back({fst,snd});
    }
    cout<<"0 ";
    for(long i=n-1;i!=0;i--){
        long minSum = INT_MAX;
        long Sum=0;
        checkpath(Sum,i,minSum);
        memo[i]=minSum;
        if(minSum==INT_MAX){
            minSum=-1;
        }
        cout<<minSum<<" ";
    }
    
}
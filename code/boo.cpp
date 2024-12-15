#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include<set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    for(int i=0;i<m;i++){
        int a;
        cin>>a;
        pq.push({a,a});
    }
    int minsum=0;
    int piece=0;
    while(piece<n){
        auto [now,con]=pq.top();
        pq.pop();
        minsum=now;
        pq.emplace(now+con,con);
        piece++;
    }
    cout<<minsum;
}
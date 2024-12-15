#include <iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n,m,k;
    cin>>n>>m>>k;
    vector<long long> a(n);
    vector<long long> b(n);
    vector<long long> c(n);
    for(int i=0;i<n;i++){
        long long line;
        cin>>line;
        a[i]=line;
        b[i]=(i==0)? line+k:b[i-1]+line+k;
        c[i]=(i==0)? line:c[i-1]+line;
    }
    for(long long i=0;i<m;i++){
        long long start,money;
        cin>>start>>money;
        if(money<b[0]){
            cout<<0<<"\n";
            continue;
        }
        long long offset =(start==0)? 0:b[start-1];
        auto it=upper_bound(b.begin(),b.end(),offset+money);
        it--;
        long long idx=it-b.begin();
        cout<<offset<<endl;
        cout<<c[idx]-((start>0)?c[start-1]:0)<<"\n";
    }
    for(auto x:b) cout<<x<<" ";
}
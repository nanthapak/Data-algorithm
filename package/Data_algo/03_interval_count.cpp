#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    long n,m,k,inp;
    vector<long> vec;
    set<long> ss;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        cin>>inp;
        // vec.push_back(inp);
        ss.insert(inp);
    }
    for(int i=0;i<m;i++){
        cin>>inp;
        long count=0;
        // for(int j=0;j<n;j++){
        //     if(vec[j]>=(inp-k)&&vec[j]<=(inp+k)) count++;
        //     if()
        // }
        auto it1 = ss.lower_bound(inp-k);
        auto it2 = ss.upper_bound(inp+k);
        for(auto it=it1;it!=it2;it++){
            count++;
        }
        cout<<count<<" ";
    }
}
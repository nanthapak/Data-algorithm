#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    vector<pair<int,int>> vec(n);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        vec[i]={a,b};
    }
    sort(vec.begin(),vec.end());
    vector<int> index(n);
    index[0]=0;
    for(int i=1;i<n;i++){
        index[i]=index[i-1]+vec[i-1].second;
    }
    for(int i=0;i<q;i++){
        int k;
        cin>>k;
        k--;
        auto it=upper_bound(index.begin(),index.end(),k);
        cout<<vec[it-index.begin()-1].first<<"\n";
    }

}

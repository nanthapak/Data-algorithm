#include <iostream>
#include <vector>
#include<climits>
#include<algorithm>
using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n;
    int last=0;
    cin>>n;
    vector<int> vec(n-1,0);
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=0;j<n;j++){
            int num;
            cin>>num;
            sum+=num;
        }
        vec[sum]+=1;
        last=max(sum,last);
    }
    for(int i=0;i<=last;i++) cout<<vec[i]<<" ";
}
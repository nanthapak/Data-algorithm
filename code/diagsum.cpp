#include <iostream>
#include <vector>
#include<climits>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<int>> vec(n,vector<int>(n));
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>vec[i][j];
            if(i>0&&j>0){
                vec[i][j]=max(vec[i][j],vec[i][j]+vec[i-1][j-1]);
            }
            maxi=max(maxi,vec[i][j]);
        }
    }
    cout<<maxi;
}
#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<set>
#include<algorithm>
using namespace std;

int main(){
    int n;
    vector<int> seq(n);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>seq[i];
    }
    int max=INT_MIN;
    pair<int,int> idx;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=seq[j];
            if(sum>max){
                max=sum;
                idx={i,j};
            }
        }
    }
    if(max<=0) cout<<"Empty sequence";
    else{
    for(int k=idx.first;k<=idx.second;k++){
        cout<<seq[k]<<" ";
    }
    cout<<endl<<max;}
    return 0;
}
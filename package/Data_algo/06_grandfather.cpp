#include <iostream>
#include <vector>
#include <set>
#include<algorithm>
#include<map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); 
    long long F,S,a1,a2;
    map<long long,long long> mup;
    long N,M;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>F>>S;
        mup[S]=F;
    }
    for(int i=0;i<M;i++){
        cin>>a1>>a2;
        if(mup.find(a1)==mup.end()||mup.find(a2)==mup.end()||a1==a2||mup[a1]==a2||mup[a2]==a1){
            cout<<"NO"<<endl;
            continue;

        }
        if(mup[mup[a1]]==mup[mup[a2]]){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }    
    
}
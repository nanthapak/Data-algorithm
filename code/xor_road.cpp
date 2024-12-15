#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

unsigned long long Beuty(int n,vector<unsigned long>&code){
    vector<bool> visited(n,false);
    vector<unsigned long> weigth(n,0);
    unsigned long long totalbeauty=0;
    visited[0]=true;
    for(int i=1;i<n;i++){
        weigth[i]=code[0]^code[i];
    }
    for(int e=0;e<n-1;e++){
        int maxedge=0,nextnode=-1;
        for(int i=0;i<n;i++){
            if(!visited[i]&&weigth[i]>maxedge){
                maxedge=weigth[i];
                nextnode=i;
            }
        }
    
        visited[nextnode]=true;
        totalbeauty+=maxedge;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                int xorval=code[nextnode]^code[i];
                if(xorval>weigth[i]) weigth[i]=xorval;
            }
        }
    }
    return totalbeauty;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<unsigned long> code(n);
    for(int i=0;i<n;i++){
        cin>>code[i];
    }
    cout<<Beuty(n,code);
}
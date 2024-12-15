#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        bool cycle=false;
        double n;
        cin>>n;
        vector<vector<double>> dist(n,vector<double>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>dist[i][j];
            }
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    dist[i][j]=max(dist[i][j],dist[i][k]*dist[k][j]);
                    if(dist[j][j]>1){
                        cycle=true;
                        break;
                    }
                }
                if(cycle) break;
            }
            if(cycle) break;
        }

        if(cycle)cout<<"NO";
        else cout<<"YES";
        cout<<endl;
    }
}
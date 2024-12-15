#include<iostream>
#include<vector>
#include<set>
using namespace std;
int main(){
    long N,M,inp1,inp2;
    vector<long> vec;
    set<long> ss;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>inp1;
        vec.push_back(inp1);
        ss.insert(inp1);
    }
    for(int j=0;j<M;j++){
        cin>>inp2;
        bool pass=false;
        for(int i=0;i<N;i++){
            long now=inp2-vec[i];
            for(int k=0;k<N;k++){
                if(now==vec[k]&&k!=i){
                    pass=true;
                    cout<<vec[i]<<" "<<vec[k];
                }
            }
        }
        if(pass){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
}
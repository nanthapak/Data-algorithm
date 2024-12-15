#include <iostream>
#include <vector>
#include <set>
#include<algorithm>
using namespace std;

int main(){
    int N,inp;
    set<int> ss,ss1;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>inp;
        ss.insert(inp);
        ss1.insert(i+1);
    }
    if(ss==ss1){
        cout<<"YES";
    }
    else cout<<"NO";
}
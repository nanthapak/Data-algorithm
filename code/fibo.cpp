#include <iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int main(){
    int n;
    cin>>n;
    int f1=0;
    int f2=1;
    int temp;
    for(int i=0;i<=n-2;i++){
        temp=f1;
        f1=f2;
        f2=f2+temp;
    }
    cout<<f2;
}
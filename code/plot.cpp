#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include<set>
#include<cmath>
using namespace std;
int main(){
    int n;
    int modi=pow(10,9)+7;
    cin>>n;
    if(n==1) cout<<1;
    else if(n==2) cout<<3;
    else{
        int first =5;
        int second=11;
        for(int i=3;i<n;i++){
            int temp=((second%modi)+((2*(first%modi))))%modi;
            first=second%modi;
            second=temp;
        }
        cout<<first%modi;
    }
}
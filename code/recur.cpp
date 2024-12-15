#include <iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

void recur(vector<vector<int>> &v,int a,int b,int top,int bottom,int left,int right){
    if(a==0){
        v[top][left]=b;
        return;
    }

    recur(v,a-1,b,top,(top+bottom)/2,left,(left+right)/2);

    recur(v,a-1,b-1,top,(top+bottom)/2,(left+right)/2,right);

    recur(v,a-1,b+1,(top+bottom)/2,bottom,left,(left+right)/2);

    recur(v,a-1,b,(top+bottom)/2,bottom,(left+right)/2,right);

}

int main(){
    int A,B;
    cin>>A>>B;
    vector<int> temp(1<<A);
    vector<vector<int>> v(1<<A,temp);
    recur(v,A,B,0,1<<A,0,1<<A);
    for(auto &x:v){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
}
#include <iostream>
#include <vector>
using namespace std;

void walk(int r,int c,vector<vector<int>> &vec,int a,int b,string sol){
    if(a==r&&b==c){
        cout<<sol<<endl;
        return;
    }
    if(b+1<=c&&vec[a][b+1]==0){
        vec[a][b]=1;
        sol+="A";
        walk(r,c,vec,a,b+1,sol);
        sol.pop_back();
        vec[a][b]=0;
    }
    if(a+1<=r&&vec[a+1][b]==0){
        vec[a][b]=1;
        sol+="B";
        walk(r,c,vec,a+1,b,sol);
        sol.pop_back();
        vec[a][b]=0;
    }
    if(a-1>=1&&vec[a-1][b]==0){
        vec[a][b]=1;
        sol+="C";
        walk(r,c,vec,a-1,b,sol);
        sol.pop_back();
        vec[a][b]=0;
    }
    return;
}

int main(){
    int r,c;
    cin>>r>>c;
    vector<int> v1(c+1);
    vector<vector<int>> vec(r+1,v1);
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            int input;
            cin>>input;
            vec[i][j]=input;
        }
    }
    string sol="";
    walk(r,c,vec,1,1,sol);
    cout<<"DONE";
}
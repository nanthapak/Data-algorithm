#include<iostream>
#include<map>
#include<vector>
using namespace std;
long R,C;
long inp;
vector<vector<long>> lst;
string ans="";
void findpath(long r,long c){
    if(r==R-1&&c==C-1) {
        cout<<ans<<endl;
        return;
    }
    //lst[r][c]=1;
    for(int k=0;k<3;k++){
        if(k==0){
            if(c + 1 < C &&lst[r][c+1]==0){
                ans+="A";
                lst[r][c]=1;
                findpath(r,c+1);
                ans.pop_back();
                lst[r][c] = 0;
            }
        }
        else if(k==1){
            if(r + 1 < R&&lst[r+1][c]==0){
                ans+="B";
                lst[r][c]=1;
                findpath(r+1,c);
                ans.pop_back();
                lst[r][c] = 0;
            }
        }
        else if(k==2){
            if(r - 1 >= 0 &&lst[r-1][c]==0){
                ans+="C";
                lst[r][c]=1;
                findpath(r-1,c);
                ans.pop_back();
                lst[r][c] = 0;
            }
        }
    }
    //lst[r][c] = 0;
}

int main(){
    cin>>R>>C;
    lst.resize(R, vector<long>(C));
    for(long i=0;i<R;i++){
        for(long j=0;j<C;j++){
            cin>>inp;
            lst[i][j]=inp;
        }
    }
    findpath(0,0);
    cout<<"DONE";
}
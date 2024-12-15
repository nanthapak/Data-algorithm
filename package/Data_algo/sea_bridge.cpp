#include<iostream>
#include<vector>
#include<map>
#include<climits>
using namespace std;
long R,C;
int inp;
vector<vector<int>> lst;

void makepath(int r,int c,int &minsum){
    
}

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    cin>>R>>C;
    lst.resize(R, vector<int>(C));
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>inp;
            lst[i][j]=inp;
        }
    }
    int minsum=INT_MAX;
    makepath(R,C,minsum);
    cout<<minsum;
}
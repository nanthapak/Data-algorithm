#include <iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;


bool check(vector<int> &vec,int start,int stop,int len){

    if(len==2) return true;

    int middle=(start + stop) / 2;
    int count1=0;
    int count2=0;
    int temp=middle;
    for(int i=start;i<middle;i++){
        if(vec[i]==1) count1++;
        if(vec[temp++]==1) count2++;
    }
    if(abs(count1-count2)>1) return false;
    return check(vec,start,middle,len/2)&&check(vec,middle,stop,len/2);
    
}

int main(){
    int n,k;
    cin>>n>>k;
    k=1<<k;
    vector<int> vec(k);
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            int bits;
            cin>>bits;
            vec[j]=bits;
        }
        if(check(vec,0,k,k)) cout<<"yes";
        else cout<<"no";
        cout<<endl;
    }
}
#include <iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int check(vector<int> &vec,int num,int start,int stop){
    int middle=(start+stop)/2;
    if(start==0&&stop==0&&vec[middle]>num) return -1;
    if(start==stop) return (vec[middle]==num)? num:vec[middle-1]; 
    if(vec[middle]>num){
        return check(vec,num,start,middle);
    }
    return check(vec,num,middle+1,stop);
} 

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> vec(n);
    for(int i=0;i<n;i++){
        int input;
        cin>>input;
        vec[i]=input;
    }
    for(int i=0;i<m;i++){
        int num,start,stop;
        start=0;
        stop=vec.size();
        cin>>num;
        cout<<check(vec,num,start,stop)<<endl;
    }
}
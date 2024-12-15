#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    vector<int> v ={1,2,3,4,5,6};
    auto it=v.begin();
    while(it!=v.end()){
        cout<<*it<<"this"<<endl;
        if(*it++==3) cout<<*it<<endl;
        
    }
}
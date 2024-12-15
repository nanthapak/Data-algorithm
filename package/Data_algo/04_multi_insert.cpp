#include <iostream>
#include <vector>
using namespace std;
void multiple_add(vector<int> &v, int value, int position, int count) {
    if(position!=v.size()){
        v.resize(v.size()+count,0);
            for(int i=v.size()-1;i!=0;i--){
                if(i-count>position){
                    v[i]=v[i-count];
                }
                else if(i-count==position){
                    v[i]=v[i-count];
                    for(int k=1;k<=count;k++){
                        v[i-k]=value;
                    }
                    break;
                }
    }
    }
    else{
        v.resize(v.size()+count,value);
    }
}
int main() {
 std::ios_base::sync_with_stdio(false);
 cin.tie(0);
 int n,value,position,count;
 cin >> n >> value >> position >> count;
 vector<int> v(n);
 for (int i = 0; i < n; i++) cin >> v[i];
 multiple_add(v,value,position,count);
 cout << "After call multiple_add" << endl << "Size = " << v.size() << endl;
 for (auto &x : v) cout << x << " ";
 cout << endl;
}
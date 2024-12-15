#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
void insertion_sort(vector<int> &A) {
    for (int pos = A.size()-2;pos >= 0;pos--) {
        int tmp = A[pos];
        int count=0;
        size_t i = pos+1;
        while (i < A.size() && A[i] < tmp) {
            A[i-1] = A[i];
            count++;
            i++;
        }
        A[i-1] = tmp;
        cout<<tmp<<" "<<count<<endl;
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> vec(n);
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        vec[i]=a;
    }
    insertion_sort(vec);
    for(auto x:vec) cout<<x<<" ";
    cout<<endl;
}
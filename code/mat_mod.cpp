#include <iostream>
#include <vector>
#include<map>
using namespace std;
map<int,vector<int>> m;
vector<int> mulmat( const vector<int>& mat1, const vector<int>& mat2, int k) {
    vector<int> temp(4, 0);
    temp[0] = ((mat1[0] * mat2[0]) % k + (mat1[1] * mat2[2]) % k) % k;
    temp[1] = ((mat1[0] * mat2[1]) % k + (mat1[1] * mat2[3]) % k) % k;
    temp[2] = ((mat1[2] * mat2[0]) % k + (mat1[3] * mat2[2]) % k) % k;
    temp[3] = ((mat1[2] * mat2[1]) % k + (mat1[3] * mat2[3]) % k) % k;
    return temp; 
}


vector<int> matmod(int n, int k) {
    if(n==1) return m[1];
    if(m.find(n)!=m.end()) return m[n];
    if(n%2==0){
        m[n]=mulmat(matmod(n/2,k),matmod(n/2,k),k);
        return m[n];
    }
    m[n]=mulmat(matmod(n/2,k),matmod((n/2)+1,k),k);
    return m[n];

}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> sol(4, 0);
    for (int i = 0; i < 4; i++) {
        int line;
        cin >> line;
        sol[i] = line;
    }
    m[1]=sol;
    sol=matmod(n, k);

    for (const auto& x : sol) {
        cout << x << " ";
    }

    return 0;
}

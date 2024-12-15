#include <iostream>
#include <vector>
using namespace std;

void consec(int n, int m, int len, vector<int> &sol, int count, bool last, bool valid) {
    if (len < n) {

        sol[len] = 0;
        consec(n, m, len + 1, sol, 0, false, valid || (count >= m));


        sol[len] = 1;
        consec(n, m, len + 1, sol, last ? count + 1 : 1, true, valid || (count + 1 >= m));
    } else {
        
        if (valid || count >= m) {
            for (auto x : sol) cout << x;
            cout << endl;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> sol(n); 
    consec(n, m, 0, sol, 0, false, false); 
    return 0;
}

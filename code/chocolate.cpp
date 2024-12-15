#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

map<long long, long long> memo; 

long long ways(set<long long> &s, long long n) {
    if (n == 0) return 1; 
    if (n < 0) return 0;  

    if (memo.find(n) != memo.end()) {
        return memo[n]; 
    }

    long long count = 0;
    for (auto &x : s) {
        count += (ways(s, n - x))%1000003; 
    }

    memo[n] = count;
    return count;
}

int main() {
    long long n, m;
    cin >> n >> m;

    set<long long> s;
    for (long long i = 0; i < m; i++) {
        long long input;
        cin >> input;
        s.insert(input);
    }

    long long ans=ways(s,n);
    if(ans<0) ans=-ans;
    cout<<ans%1000003;
}

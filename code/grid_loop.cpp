#include<iostream>
#include<vector>
#include<map>
using namespace std;

int modi = 1e8 + 7;
map<pair<pair<int, int>, int>, int> memo;
int r, c;
vector<pair<int, int>> pos = {{-1, 1}, {0, 1}, {1, 1}};

int dfs(vector<vector<int>> &table, int x, int y, int type) {
    if (y == c - 1) return 1;
    if (memo.find({{x, y}, type}) != memo.end()) 
        return memo[{{x, y}, type}];
    
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        int nx = x + pos[i].first;
        int ny = y + pos[i].second;
        if (i != type && nx >= 0 && ny >= 0 && nx < r && ny < c && table[nx][ny] != 1) {
            sum = (sum + dfs(table, nx, ny, i)) % modi;
        }
    }
    memo[{{x, y}, type}] = sum;
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> r >> c;
    vector<vector<int>> table(r, vector<int>(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> table[i][j];
        }
    }
    
    int summ = 0;
    for (int i = 0; i < r; i++) {
        if (table[i][0] != 1) {
            summ = (summ + dfs(table, i, 0, -1)) % modi;
        }
    }
    cout << summ % modi;
    return 0;
}

#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }

    int maxi = 0;
    int from = 0;
    vector<int> dist(n, INT_MAX);
    vector<int> prev(n, -1);
    dist[from] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, from});

    while (!pq.empty()) {
        auto [T, node] = pq.top();
        pq.pop();

        for (int x = 0; x < n; x++) {
            if (adj[node][x] != -1 && adj[node][x] != 0 && dist[x] > T + adj[node][x]) {
                dist[x] = T + adj[node][x];
                prev[x] = node;
                pq.push({dist[x], x});
            }
        }
    }

    int count = 0;
    for (auto &x : dist) {
        if (x != INT_MAX) {
            maxi = max(maxi, x);
        } else {
            count++;
        }
    }

    cout << (count == 0 ? maxi : -1);
}

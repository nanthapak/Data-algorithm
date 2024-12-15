#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, c;
    cin >> n >> c;

    // Adjacency list representation
    vector<vector<pair<int, int>>> adj(n + 1);
    adj[1].push_back({2, c});
    adj[2].push_back({1, c});

    // Process each query
    for (int i = 3; i <= n; i++) {
        int k;
        cin >> k;

        for (int j = 0; j < k; j++) {
            int t, p;
            cin >> t >> p;
            adj[i].push_back({t, p});
            adj[t].push_back({i, p});
        }

        // Dijkstra's Algorithm
        vector<int> dist(n + 1, INT_MAX);
        vector<bool> visited(n + 1, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[1] = 0;
        pq.push({0, 1});

        while (!pq.empty()) {
            auto [T, node] = pq.top();
            pq.pop();

            if (visited[node]) continue;
            visited[node] = true;

            for (auto [neighbor, weight] : adj[node]) {
                if (!visited[neighbor] && dist[neighbor] > T + weight) {
                    dist[neighbor] = T + weight;
                    pq.push({dist[neighbor], neighbor});
                }
            }
        }


        cout << dist[2] << " ";
    }
}

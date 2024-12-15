#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <limits>
using namespace std;

// Directions for neighbors (up, down, left, right)
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int main() {
    int r, c;
    cin >> r >> c;

    // Input grid
    vector<vector<int>> grid(r, vector<int>(c));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> grid[i][j];
        }
    }

    // Distance matrix
    vector<vector<int>> dist(r, vector<int>(c, numeric_limits<int>::max()));
    dist[0][0] = grid[0][0];

    // Priority queue (min-heap), storing tuples of (distance, x, y)
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    pq.emplace(grid[0][0], 0, 0);

    // Dijkstra's algorithm
    while (!pq.empty()) {
        auto [current_dist, x, y] = pq.top();
        pq.pop();

        // If current distance is greater than recorded distance, skip
        if (current_dist > dist[x][y]) continue;

        // Explore neighbors
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // Check bounds
            if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
                int new_dist = current_dist + grid[nx][ny];
                if (new_dist < dist[nx][ny]) {
                    dist[nx][ny] = new_dist;
                    pq.emplace(new_dist, nx, ny);
                }
            }
        }
    }

    // Output the distance matrix
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

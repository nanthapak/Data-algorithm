#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<set>
#include<algorithm>
using namespace std;

void printPath(const vector<int>& prev, int node) {
    if (node == -1) return;  // Base case: no path exists
    cout << node << " ";
    printPath(prev, prev[node]);  // Recursive call for previous node  // Print the current node
}

int main(){
    int n, e, s;
    cin >> n >> e >> s;  // n = number of nodes, e = number of edges, s = source node
    vector<pair<int, pair<int, int>>> edges;
    
    for(int i = 0; i < e; i++){
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c, {a, b}});  // Directed edge from a -> b with weight c
    }
    
    vector<int> dist(n, INT_MAX);  // Distance vector initialized to infinity
    vector<int> prev(n, -1);       // Previous node vector initialized to -1
    dist[s] = 0;                   // Distance to source node is 0
    
    // Relax edges n-1 times
    for(int i = 1; i < n; i++){
        for(auto &[w, a] : edges){
            if(dist[a.first] != INT_MAX && dist[a.second] > dist[a.first] + w){
                dist[a.second] = dist[a.first] + w;
                prev[a.second] = a.first;
            }
        }
    }
    
    // Check for negative weight cycle
    bool negcycle = false;
    for(auto &[w, a] : edges){
        if(dist[a.first] != INT_MAX && dist[a.second] > dist[a.first] + w){
            negcycle = true;
            break;
        }
    }

    // Output result
    if(negcycle) {
        cout << -1 << endl;
    } else {
        // Print the shortest distances
        for(auto &x : dist) {
            if (x == INT_MAX) 
                cout << "INF ";  // No path exists
            else 
                cout << x << " ";
        }
        cout << endl;

        // Print the shortest path for each node
        for (int i = 0; i < n; i++) {
            if (dist[i] == INT_MAX)
                cout << "No path to " << i << endl;  // If no path exists
            else {
                cout << "Path to " << i << ": ";
                printPath(prev, i);  // Reconstruct and print the path
                cout << endl;
            }
        }
    }

    return 0;
}
// 4 4 0 
// 0 1 10
// 0 2 5
// 1 2 2
// 2 3 1
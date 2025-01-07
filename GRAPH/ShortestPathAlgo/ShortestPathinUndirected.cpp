#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int n = adj.size();  // Number of nodes
        
        // Distance array initialized to a large number (infinity)
        vector<int> dist(n, 1e9);
        
        // Queue for BFS traversal
        queue<int> q;
        
        // Distance to source node is 0
        dist[src] = 0;
        q.push(src);
        
        // BFS traversal
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            // Explore all adjacent nodes
            for (auto it : adj[node]) {
                if (dist[node] + 1 < dist[it]) {
                    dist[it] = dist[node] + 1;  // Update distance
                    q.push(it);  // Add to queue for further exploration
                }
            }
        }
        
        // Mark unreachable nodes as -1
        for (int i = 0; i < n; i++) {
            if (dist[i] == 1e9) {
                dist[i] = -1;
            }
        }
        
        return dist;  // Return the distance array
    }
};

int main() {
    // Example graph (adjacency list)
    int N = 9, M = 10;
    vector<vector<int>> edges = {
        {0, 1}, {0, 3}, {3, 4}, {4, 5}, {5, 6}, {1, 2}, {2, 6}, {6, 7}, {7, 8}, {6, 8}
    };

    // Create adjacency list from edges
    vector<vector<int>> adj(N);  // Change to 2D vector
    for (auto it : edges) {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    int src = 0;  // Starting point for BFS

    Solution obj;
    vector<int> ans = obj.shortestPath(adj , src);

    // Output the shortest path distances from the source to all other vertices
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}

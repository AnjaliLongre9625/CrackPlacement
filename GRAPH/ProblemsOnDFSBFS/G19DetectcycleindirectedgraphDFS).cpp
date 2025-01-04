#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis) {
        vis[node] = 1;   // Mark node as visited
        pathVis[node] = 1; // Mark node as part of the current path
        
        for (auto it : adj[node]) {
            // If the node is not visited
            if (vis[it] == 0) {
                if (dfs(it, adj, vis, pathVis)) {
                    return true;  // Cycle detected
                }
            }
            // If the node is visited and is part of the current path
            else if (pathVis[it]) {
                return true;  // Cycle detected
            }
        }
        
        pathVis[node] = 0; // Unmark the node from the current path
        return false;  // No cycle found
    }

    bool isCyclic(int V, vector<vector<int>>& adj) {
        vector<int> vis(V, 0);    // Visited array to mark visited nodes
        vector<int> pathVis(V, 0); // Array to track the current path
        
        for (int i = 0; i < V; i++) {
            if (vis[i] == 0) {  // If the node is not visited yet
                if (dfs(i, adj, vis, pathVis)) {
                    return true;  // Cycle found
                }
            }
        }
        return false;  // No cycle found
    }
};

int main() {
    int V = 4; // Number of vertices
    vector<vector<int>> adj(V);

    // Adding edges to the graph
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(0);

    Solution sol;
    if (sol.isCyclic(V, adj)) {
        cout << "Graph contains a cycle." << endl;
    } else {
        cout << "Graph does not contain a cycle." << endl;
    }

    return 0;
}

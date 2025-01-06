#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph {
public:
    // Function to perform a DFS traversal
    void dfs(int node, vector<int>& vis, stack<int>& st, vector<vector<int>>& adj) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, vis, st, adj);
            }
        }
        st.push(node);
    }

    // Function to perform Topological Sort
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        int V = adj.size();  // Number of vertices
        vector<int> vis(V, 0);
        stack<int> st;

        // Perform DFS for each unvisited node
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, st, adj);
            }
        }

        // Extract the topological order from the stack
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<int>> adj(V);
    cout << "Enter the edges (from -> to):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);  // Directed edge from u to v
    }

    Graph g;
    vector<int> topoSort = g.topologicalSort(adj);

    cout << "Topological Sort: ";
    for (int node : topoSort) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

// Dijkstra's algorithm function
vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
    int V = adj.size();
    vector<int> dist(V, 1e9); // Initialize distances to infinity
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int currDist = pq.top().first; // Current distance
        int node = pq.top().second;    // Current node
        pq.pop();

        for (auto it : adj[node]) {
            int adjNode = it.first;    // Adjacent node
            int edgeWt = it.second;    // Weight of the edge

            if (currDist + edgeWt < dist[adjNode]) {
                dist[adjNode] = currDist + edgeWt;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}

int main() {
    // Example graph representation
    // Number of nodes: 4
    // Edges: 
    // 0 -> 1 (weight 2), 0 -> 2 (weight 4)
    // 1 -> 2 (weight 1)
    // 2 -> 3 (weight 3)
    vector<vector<pair<int, int>>> adj = {
        {{1, 2}, {2, 4}},  // Node 0 connects to Node 1 (weight 2), Node 2 (weight 4)
        {{2, 1}},          // Node 1 connects to Node 2 (weight 1)
        {{3, 3}},          // Node 2 connects to Node 3 (weight 3)
        {}                 // Node 3 has no outgoing edges
    };

    int src = 0; // Starting node
    vector<int> distances = dijkstra(adj, src);

    // Print distances from the source node
    for (int i = 0; i < distances.size(); i++) {
        cout << "Distance from Node " << src << " to Node " << i << ": " << distances[i] << endl;
    }

    return 0;
}

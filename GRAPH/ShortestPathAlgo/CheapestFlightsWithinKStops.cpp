#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<pair<int, int>> adj[n];
        for (auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        vector<int> dist(n, 1e9);
        dist[src] = 0;

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if (stops > K) continue;

            for (auto it : adj[node]) {
                int adjNode = it.first;
                int edgewt = it.second;
                if (cost + edgewt < dist[adjNode] && stops <= K) {
                    dist[adjNode] = cost + edgewt;
                    q.push({stops + 1, {adjNode, cost + edgewt}});
                }
            }
        }

        if (dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};

int main() {
    Solution obj;
    int n = 4; // Number of nodes
    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {2, 3, 100}, {0, 2, 500}};
    int src = 0;
    int dst = 3;
    int K = 1;

    int result = obj.CheapestFLight(n, flights, src, dst, K);
    cout << "Cheapest price flights: " << result << endl;

    return 0;
}

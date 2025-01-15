#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void shortestDistance(vector<vector<int>>& mat) {
        int n = mat.size();

        // Step 1: Initialize the matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == -1) {
                    mat[i][j] = 1e9; // Treat -1 as infinite distance
                }
                if (i == j) {
                    mat[i][j] = 0; // Distance to self is 0
                }
            }
        }

        // Step 2: Update matrix using the Floyd-Warshall algorithm
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (mat[i][k] < 1e9 && mat[k][j] < 1e9) { // Avoid overflow
                        mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                    }
                }
            }
        }

        // Step 3: Replace infinite distances back to -1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1e9) {
                    mat[i][j] = -1;
                }
            }
        }
    }
};

// Example usage
int main() {
    Solution sol;
    vector<vector<int>> mat = {
        {0, 3, -1, 7},
        {-1, 0, 2, -1},
        {-1, -1, 0, 1},
        {6, -1, -1, 0}
    };

    sol.shortestDistance(mat);

    // Print the updated matrix
    for (const auto& row : mat) {
        for (int dist : row) {
            cout << dist << " ";
        }
        cout << endl;
    }

    return 0;
}

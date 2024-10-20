#include <bits/stdc++.h>
using namespace std;

// Recursive function to calculate the maximum chocolates
int f(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp) {
    // Base case: Out of bounds conditions
    if (j1 < 0 || j2 < 0 || j1 >= c || j2 >= c)
        return -1e8;
    
    // Base case: If we have reached the last row
    if (i == r - 1) {
        if (j1 == j2) return grid[i][j1]; // If both are on the same cell, count once
        else return grid[i][j1] + grid[i][j2]; // Else, count both
    }

    // Check if already calculated
    if (dp[i][j1][j2] != -1) return dp[i][j1][j2];

    // Explore all possible moves
    int maxi = -1e8;
    for (int dj1 = -1; dj1 <= +1; dj1++) {
        for (int dj2 = -1; dj2 <= +1; dj2++) {
            int value = 0;
            if (j1 == j2) value = grid[i][j1]; // If both are at the same cell
            else value = grid[i][j1] + grid[i][j2]; // Otherwise, sum of both
            value += f(i + 1, j1 + dj1, j2 + dj2, r, c, grid, dp); // Recur for the next row
            maxi = max(maxi, value); // Keep track of the maximum
        }
    }
    return dp[i][j1][j2] = maxi; // Store the result in the DP table
}

// Function to initiate the DP solution
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
    return f(0, 0, c - 1, r, c, grid, dp); // Start from row 0, and columns 0 and c-1
}

// Main function to test the solution
int main() {
    int r, c;
    cin >> r >> c; // Input the number of rows and columns

    vector<vector<int>> grid(r, vector<int>(c)); // Input the grid
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> grid[i][j];
        }
    }

    cout << maximumChocolates(r, c, grid) << endl; // Output the maximum chocolates collected

    return 0;
}

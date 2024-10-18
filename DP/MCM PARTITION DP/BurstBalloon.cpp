#include <bits/stdc++.h>
using namespace std;

int f(int i, int j, vector<int>& a, vector<vector<int>>& dp) {
    if (i > j) return 0; // Base case
    if (dp[i][j] != -1) return dp[i][j]; // Return memoized result

    int maxi = INT_MIN;
    for (int ind = i; ind <= j; ind++) {
        int cost = a[i - 1] * a[ind] * a[j + 1] + f(i, ind - 1, a, dp) + f(ind + 1, j, a, dp);
        maxi = max(maxi, cost); // Maximize result
    }
    
    return dp[i][j] = maxi; // Store result in dp table
}

int maxCoins(vector<int>& a) {
    int n = a.size();
    a.push_back(1); // Add 1 at the end
    a.insert(a.begin(), 1); // Add 1 at the beginning

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1)); // Initialize dp table

    return f(1, n, a, dp); // Call recursive function
}

int main() {
    // Example test case
    vector<int> balloons = {3, 1, 5, 8};  // Balloons array
    cout << "Maximum coins that can be collected: " << maxCoins(balloons) << endl;

    return 0;
}

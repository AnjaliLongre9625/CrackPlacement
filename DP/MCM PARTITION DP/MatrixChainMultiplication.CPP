#include <bits/stdc++.h>
using namespace std;

int f(int i, int j, vector<int>& arr, vector<vector<int>>& dp) {
    if (i == j) return 0;
    int mini = INT_MAX;  
    int steps = 0;
    
    if (dp[i][j] != -1) return dp[i][j]; 
    
    for (int k = i; k < j; k++) {
        steps = arr[i-1] * arr[k] * arr[j] + f(i, k, arr, dp) + f(k + 1, j, arr, dp);
        if (mini > steps) {
            mini = steps;
        }
    }
    
    return dp[i][j] = mini;  // Store and return the result.
}

int matrixMultiplication(vector<int>& arr, int N) {
    vector<vector<int>> dp(N, vector<int>(N, -1));
    
    return f(1, N - 1, arr, dp);
}

int main() {
    // Example input: dimensions of matrices.
    vector<int> arr = {1, 2, 3, 4};  // Represents matrices with dimensions: 1x2, 2x3, 3x4
    
    int N = arr.size();
    
    // Function call to get the minimum multiplication cost.
    int result = matrixMultiplication(arr, N);
    
    // Output the result.
    cout << "Minimum number of multiplications: " << result << endl;

    return 0;
}

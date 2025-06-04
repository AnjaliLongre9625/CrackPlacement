
#include <bits/stdc++.h>
using namespace std;

int helper(int ind, int W, vector<int>& val, vector<int>& wt, vector<vector<int>>& dp) {
   
    if (ind == 0) {
        return (W / wt[0]) * val[0];
    }

    if (dp[ind][W] != -1) return dp[ind][W];

    int nottake = helper(ind - 1, W, val, wt, dp);
    int take = INT_MIN;

    if (wt[ind] <= W) {
        take = val[ind] + helper(ind, W - wt[ind], val, wt, dp);
    }

    return dp[ind][W] = max(take, nottake);
}

int unboundedKnapsack(int n, int W, vector<int>& val, vector<int>& wt) {
    vector<vector<int>>dp(n,vector<int>(W+1,-1));
    return helper(n-1,W,val,wt,dp);
}

int main() {
    vector<int> wt = {2, 4, 6}; // Weight of items
    vector<int> val = {5, 11, 13}; // Value of items
    int W = 10; // Weight capacity of the knapsack
    int n = wt.size(); // Number of items
    
    // Call the function to calculate and output the maximum value the thief can steal
    cout << "The Maximum value of items the thief can steal is " << unboundedKnapsack(n, W, val, wt) << endl;

    return 0; // Return 0 to indicate successful program execution
}


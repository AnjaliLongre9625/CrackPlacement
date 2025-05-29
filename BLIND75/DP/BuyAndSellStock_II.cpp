#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(int ind, int buy, vector<int>& prices, vector<vector<int>>& dp) {
        int n = prices.size();
        if (ind == n) return 0;

        if (dp[ind][buy] != -1) return dp[ind][buy];

        int profit = 0;
        if (buy) {
            profit = max(-prices[ind] + helper(ind + 1, 0, prices, dp),
                         0 + helper(ind + 1, 1, prices, dp)); // buy or skip
        } else {
            profit = max(prices[ind] + helper(ind + 1, 1, prices, dp),
                         0 + helper(ind + 1, 0, prices, dp)); // sell or skip
        }

        return dp[ind][buy] = profit;
    }
//. Tabulation (Bottom-up DP)
// int tabulationMaxProfit(vector<int>& prices) {
//     int n = prices.size();
//     vector<vector<int>> dp(n + 1, vector<int>(2, 0));

//     for (int ind = n - 1; ind >= 0; ind--) {
//         for (int buy = 0; buy <= 1; buy++) {
//             if (buy) {
//                 dp[ind][buy] = max(-prices[ind] + dp[ind + 1][0],
//                                    0 + dp[ind + 1][1]);
//             } else {
//                 dp[ind][buy] = max(prices[ind] + dp[ind + 1][1],
//                                    0 + dp[ind + 1][0]);
//             }
//         }
//     }

//     return dp[0][1]; // Start from index 0 with buying allowed
// }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return helper(0, 1, prices, dp);
    }
};

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4}; // Example input
    Solution sol;
    int profit = sol.maxProfit(prices);
    cout << "The maximum profit that can be generated is " << profit << endl;
    return 0;
}

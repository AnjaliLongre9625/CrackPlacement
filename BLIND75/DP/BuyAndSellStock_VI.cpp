#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int helper(int ind, int buy, vector<int>& prices, vector<vector<int>>& dp, int fee) {
        if (ind == prices.size()) return 0;
        if (dp[ind][buy] != -1) return dp[ind][buy];

        if (buy) {
            dp[ind][buy] = max(
                -prices[ind] + helper(ind + 1, 0, prices, dp, fee),  // Buy
                helper(ind + 1, 1, prices, dp, fee)                   // Skip
            );
        } else {
            dp[ind][buy] = max(
                prices[ind] - fee + helper(ind + 1, 1, prices, dp, fee),  // Sell
                helper(ind + 1, 0, prices, dp, fee)                        // Skip
            );
        }
        return dp[ind][buy];
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return helper(0, 1, prices, dp, fee);
    }
};

// class Solution {
// public:
//     int maxProfit(vector<int>& prices, int fee) {
//         int n=prices.size();
//         vector<vector<int>>dp(n+1,vector<int>(2,0));

//         for(int ind=n-1;ind>=0;ind--){
//           for(int buy=0;buy<=1;buy++){
//             if(buy){
//              dp[ind][buy] = max(-prices[ind] + dp[ind + 1][0], dp[ind + 1][1]);
//          }
//         else{
//             dp[ind][buy] = max(prices[ind] - fee + dp[ind + 1][1],dp[ind + 1][0]);
//           }
//          }
//         }
//         return dp[0][1];
//     }
// };
int main() {
    Solution sol;

    // Example 1
    vector<int> prices1 = {1, 3, 2, 8, 4, 9};
    int fee1 = 2;
    cout << "Max Profit (Example 1): " << sol.maxProfit(prices1, fee1) << endl;  // Output: 8

    // Example 2
    vector<int> prices2 = {1, 3, 7, 5, 10, 3};
    int fee2 = 3;
    cout << "Max Profit (Example 2): " << sol.maxProfit(prices2, fee2) << endl;  // Output: 6

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int helper(int ind, int buy, int k, vector<int>& prices, vector<vector<vector<int>>>& dp) {
        if (ind == prices.size() || k == 0) return 0;
        if (dp[ind][buy][k] != -1) return dp[ind][buy][k];

        if (buy) {
            dp[ind][buy][k] = max(-prices[ind] + helper(ind + 1, 0, k, prices, dp),
                                  helper(ind + 1, 1, k, prices, dp));
        } else {
            dp[ind][buy][k] = max(prices[ind] + helper(ind + 1, 1, k - 1, prices, dp),
                                  helper(ind + 1, 0, k, prices, dp));
        }
        return dp[ind][buy][k];
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return helper(0, 1, k, prices, dp);
    }
};
//tabulation
// class Solution {
// public:
//     int maxProfit(int k, vector<int>& prices) {
//         int n=prices.size();
//         vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));

//         for(int ind=n-1;ind>=0;ind--){
//            for(int buy=0;buy<=1;buy++){
//               for(int cap=1;cap<=k;cap++){
//                 if(buy){
//                     dp[ind][buy][cap]=max(-prices[ind]+dp[ind+1][0][cap],0+dp[ind+1][1][cap]);
//                  }
//                 else{
//                     dp[ind][buy][cap]=max(prices[ind]+dp[ind + 1][1][cap - 1],0+dp[ind+1][0][cap]);
//                    }
//                 }
//             }
//         }
//         return dp[0][1][k];
//     }
// };


int main() {
    Solution sol;
    
    // Test case 1
    vector<int> prices1 = {3, 2, 6, 5, 0, 3};
    int k1 = 2;
    cout << "Max Profit (Test 1): " << sol.maxProfit(k1, prices1) << endl; // Expected: 7

    // Test case 2
    vector<int> prices2 = {2, 4, 1};
    int k2 = 2;
    cout << "Max Profit (Test 2): " << sol.maxProfit(k2, prices2) << endl; // Expected: 2

    // Test case 3
    vector<int> prices3 = {1, 2, 3, 4, 5};
    int k3 = 1;
    cout << "Max Profit (Test 3): " << sol.maxProfit(k3, prices3) << endl; // Expected: 4

    return 0;
}

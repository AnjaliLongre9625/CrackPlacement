#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int helper(int ind, int buy, int cap, vector<int>& prices, vector<vector<vector<int>>>& dp) {
        if (ind == prices.size() || cap == 0) return 0;
        if (dp[ind][buy][cap] != -1) return dp[ind][buy][cap];

        if (buy) {
            dp[ind][buy][cap] = max(-prices[ind] + helper(ind + 1, 0, cap, prices, dp),
                                    0 + helper(ind + 1, 1, cap, prices, dp));
        } else {
            dp[ind][buy][cap] = max(prices[ind] + helper(ind + 1, 1, cap - 1, prices, dp),
                                    0 + helper(ind + 1, 0, cap, prices, dp));
        }
        return dp[ind][buy][cap];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return helper(0, 1, 2, prices, dp);
    }
};
//tabulation
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n=prices.size();
//         vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));

//         for(int ind=n-1;ind>=0;ind--){
//            for(int buy=0;buy<=1;buy++){
//               for(int cap=1;cap<=2;cap++){
//                 if(buy){
//                     dp[ind][buy][cap]=max(-prices[ind]+dp[ind+1][0][cap],0+dp[ind+1][1][cap]);
//                  }
//                 else{
//                     dp[ind][buy][cap]=max(prices[ind]+dp[ind + 1][1][cap - 1],0+dp[ind+1][0][cap]);
//                    }
//                 }
//             }
//         }
//         return dp[0][1][2];
//     }
// };

int main() {
    Solution sol;

    // Example input
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};

    // Call maxProfit and print the result
    int profit = sol.maxProfit(prices);
    cout << "Maximum profit: " << profit << endl;

    return 0;
}

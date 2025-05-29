#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int helper(int ind, int buy, vector<int>& prices, vector<vector<int>>& dp) {
        if (ind >= prices.size()) return 0;
        if (dp[ind][buy] != -1) return dp[ind][buy];

        if (buy) {
            dp[ind][buy] = max(-prices[ind] + helper(ind + 1, 0, prices, dp),0 + helper(ind + 1, 1, prices, dp));
        } 
        else {
            dp[ind][buy] = max(prices[ind] + helper(ind + 2, 1, prices, dp),0 + helper(ind + 1, 0, prices, dp));
        }
        return dp[ind][buy];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return helper(0, 1, prices, dp);
    }
};
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n=prices.size();
//         vector<vector<int>>dp(n+2,vector<int>(2,0));

//         for(int ind=n-1;ind>=0;ind--){
//           for(int buy=0;buy<=1;buy++){
//             if(buy){
//                 dp[ind][buy]= max(-prices[ind]+dp[ind+1][0],0+dp[ind+1][1]);
//             }
//             else{
//                 dp[ind][buy]=  max(prices[ind]+dp[ind+2][1],0+dp[ind+1][0]);
//              }
//            }
//         }
//         return dp[0][1];
//     }
// };

int main() {
    Solution sol;
    vector<int> prices = {1, 2, 3, 0, 2};

    int result = sol.maxProfit(prices);
    cout << "Maximum Profit: " << result << endl;

    return 0;
}

#include<bits/stdc++.h>
using namespace std;

int f(int ind, int buy, vector<int> &prices, vector<vector<int>> &dp, int fee) {
    if (ind >= prices.size()) return 0;
    if (dp[ind][buy] != -1) return dp[ind][buy];

    if (buy == 1) {
        return dp[ind][buy] = max(-prices[ind] + f(ind + 1, 0, prices, dp, fee), 
                                  0 + f(ind + 1, 1, prices, dp, fee));
    } else {
        return dp[ind][buy] = max(prices[ind] - fee + f(ind + 1, 1, prices, dp, fee), 
                                  0 + f(ind + 1, 0, prices, dp, fee));
    }
}

int maximumProfit(vector<int> &prices, int n, int fee) {
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return f(0, 1, prices, dp, fee);
}

int main() {
    vector<int> prices = {1, 3, 2, 8, 4, 9};  // Example stock prices
    int fee = 2;  // Example transaction fee
    int n = prices.size();
    
    int result = maximumProfit(prices, n, fee);
    cout << "Maximum Profit with Transaction Fee: " << result << endl;

    return 0;
}

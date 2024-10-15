#include <iostream>
#include<vector>
using namespace std;

int maximumProfit(vector<int> &prices, int n, int k) {
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));

    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            for (int cap = 1; cap <= k; cap++) {
                if (buy == 1) {
                    // Option to buy the stock or skip
                    dp[ind][buy][cap] = max(-prices[ind] + dp[ind + 1][0][cap], 0 + dp[ind + 1][1][cap]);
                } else {
                    // Option to sell the stock or skip
                    dp[ind][buy][cap] = max(prices[ind] + dp[ind + 1][1][cap - 1], 0 + dp[ind + 1][0][cap]);
                }
            }
        }
    }
    // Return the maximum profit starting from day 0, with the option to buy, and k transactions available
    return dp[0][1][k];
}

int main() {
    // Input number of days, number of transactions, and stock prices
    int n, k;
    cout << "Enter number of days: ";
    cin >> n;
    cout << "Enter maximum number of transactions: ";
    cin >> k;
    
    vector<int> prices(n);
    cout << "Enter stock prices for " << n << " days: ";
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    // Calculate maximum profit
    int result = maximumProfit(prices, n, k);
    cout << "Maximum profit: " << result << endl;

    return 0;
}

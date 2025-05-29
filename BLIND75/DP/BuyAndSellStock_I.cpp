#include <iostream>
#include <vector>
#include <algorithm>  // For max and min
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int n= prices.size();
        int profit = 0;

        for (int i = 1; i <n; i++) {
            int cost = prices[i] - mini;
            profit = max(profit, cost);
            mini = min(mini, prices[i]);
        }
        return profit;
    }
};

int main() {
    // Example test case
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    Solution sol;
    int result = sol.maxProfit(prices);

    cout << "Maximum Profit: " << result << endl;
    return 0;
}

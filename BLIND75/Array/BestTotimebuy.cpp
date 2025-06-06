#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int mini=prices[0];
        int maxi=0;

        for(int i=1;i<prices.size();i++){
            int cost=prices[i]-mini;
            mini=min(mini,prices[i]);
            maxi=max(maxi,cost);
        }

     return maxi;
  }
};

int main() {
    Solution solution;
    vector<int> prices = {7, 1, 5, 3, 6, 4};// Example input
    int result = solution.maxProfit(prices);// Call the maxProfit function
    cout << "Maximum Profit: " << result << endl;// Output the result
    return 0;
}

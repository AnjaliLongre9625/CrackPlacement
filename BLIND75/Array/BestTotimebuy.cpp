#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int miniSoFar=prices[0];
        int maxi=0;
        for(int i=1;i<prices.size();i++){
            miniSoFar=min(miniSoFar,prices[i]);
            maxi=max(maxi,prices[i]-miniSoFar);
        }
    return maxi;
  }
};
int main() {
    Solution solution;

    // Example input
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    // Call the maxProfit function
    int result = solution.maxProfit(prices);

    // Output the result
    cout << "Maximum Profit: " << result << endl;

    return 0;
}

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
    vector<int> prices = {7, 1, 5, 3, 6, 4};// Example input
    int result = solution.maxProfit(prices);// Call the maxProfit function
    cout << "Maximum Profit: " << result << endl;// Output the result

    return 0;
}

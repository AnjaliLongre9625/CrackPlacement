#include <bits/stdc++.h>
using namespace std;
 int maxProfit(vector<int>& prices) {
        int minSoFar=prices[0];
        int maxProfit=0;

        for(int i=1;i<prices.size();i++){
            minSoFar=min(minSoFar,prices[i]);
            int profit=prices[i]-minSoFar;
            maxProfit=max(maxProfit,profit);
           }
        return maxProfit;
    }
int main(){
    vector<int> prices = {7,1,5,3,6,4};
    int ans = maxProfit(prices);
    cout << "The max profit after see=lling is: " << ans << endl;
    return 0;
}
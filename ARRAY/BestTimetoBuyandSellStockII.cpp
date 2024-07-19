#include <bits/stdc++.h>
using namespace std;
 int maxProfit(vector<int>& prices) { //peak pe bechna // bottom pe buy krna 
    int profit=0;
    for(int i=0;i<prices.size();i++){
        if(prices[i]>prices[i-1]){
           profit+=prices[i]-prices[i-1];
        }
    }
    return profit;
  }
int main(){
    vector<int> prices = {7,1,5,3,6,4};
    int ans = maxProfit(prices);
    cout << "The max profit is: " << ans << endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
bool containsDuplicate(vector<int>& nums) {
      unordered_set<int>uniqueSet;
      for(int num:nums){
          if(uniqueSet.count(num)>0){
              return true;
          }
          uniqueSet.insert(num);
      }
      return false;
     }
   };
int main() {
    Solution solution;

    // Example input
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    // Call the containsDuplicate function
    bool result = solution.containsDuplicate(prices);

    // Output the result
    cout << "containsDuplicate: " << (result ? "true" : "false") << endl;

    return 0;
}

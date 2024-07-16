//  Maximum Product of Three Numbers
#include <bits/stdc++.h>
using namespace std;

int maximumProduct(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int ans = nums[n - 1] * nums[n - 2] * nums[n - 3];
    int ans2 = nums[0] * nums[1] * nums[n - 1];
    return max(ans, ans2);
}
int main(){
    vector<int>nums={1,2,3,4};
    cout<<"max product:"<<maximumProduct(nums);
}

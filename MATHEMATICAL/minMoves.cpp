#include <bits/stdc++.h>
using namespace std;
int minMoves2(vector<int> &nums){
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int start = 0, end = n - 1;
    int count = 0;
    while (start < end){
        count += abs(nums[end] - nums[start]);
        start++;
        end--;
    }
    return count;
    }
int main()
{
    vector<int> nums = {1, 2, 3};
    cout << "Minimum moves to equalize elements: " << minMoves2(nums) << endl;
    return 0;
}
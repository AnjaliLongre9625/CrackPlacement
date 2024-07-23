#include <bits/stdc++.h>
using namespace std;
int subarraysDivByK(vector<int> &nums, int k)
{
    unordered_map<int, int> m;
    int n = nums.size();
    int ans = 0;
    int rem = 0;
    int sum = 0;

    m[rem]++;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        rem = sum % k;

        if (rem < 0)
        {
            rem += k;
        }
        if (m.find(rem) != m.end())
        {
            ans += m[rem];
        }
        m[rem]++;
    }
    return ans;
}
int main()
{
    int k = 5;
    vector<int> nums = {4, 5, 0, -2, -3, 1};
    cout << "Subarray Sums Divisible by K: " << subarraysDivByK(nums, k);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
{
    vector<long long int> left(n, 1), right(n, 1), result(n, 1);

    for (int i = 1; i < n; i++)
        left[i] = left[i - 1] * nums[i - 1];

    for (int i = n - 2; i >= 0; i--)
        right[i] = right[i + 1] * nums[i + 1];

    for (int i = 0; i < n; i++)
        result[i] = left[i] * right[i];

    return result;
}

int main()
{
    int n = 5;
    vector<long long int> nums1 = {10, 3, 5, 6, 2}; // Output: 180 600 360 300 900
    vector<long long int> result = productExceptSelf(nums1, n);

    cout << "Product array: ";
    for (long long int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
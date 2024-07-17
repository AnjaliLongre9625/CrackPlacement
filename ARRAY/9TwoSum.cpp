#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    vector<pair<int, int>> indexed_nums;

    // Fill the indexed_nums with (value, index) pairs
    for (int i = 0; i < n; i++) {
        indexed_nums.push_back({nums[i], i});
    }

    // Sort based on the values of the pairs
    sort(indexed_nums.begin(), indexed_nums.end());

    int left = 0, right = n - 1;

    while (left < right) {
        int sum = indexed_nums[left].first + indexed_nums[right].first;

        if (sum == target) {
            return {indexed_nums[left].second, indexed_nums[right].second};
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    return {}; 
}

int main() {
    int target = 10;
    vector<int> nums = {9, 6, 2, 1, 7};
    vector<int> result = twoSum(nums, target);

    if (!result.empty()) {
        cout << "Indices of the two numbers that add up to " << target << " are: ";
        for (int index : result) {
            cout << index << " ";
        }
        cout << endl;
    } else {
        cout << "No two numbers add up to " << target << endl;
    }

    return 0;
}

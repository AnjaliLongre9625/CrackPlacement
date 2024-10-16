#include <bits/stdc++.h>
using namespace std;

void sortOddEven(vector<int>& nums) {
    vector<int> odd, even;

    // Step 1: Separate odd and even numbers
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] % 2 != 0) {
            odd.push_back(nums[i]);
        } else {
            even.push_back(nums[i]);
        }
    }

    // Step 2: Sort odd in non-increasing order and even in non-decreasing order
    sort(odd.begin(), odd.end(), greater<int>());
    sort(even.begin(), even.end());

    // Step 3: Merge sorted odd and even numbers back into the array
    int index = 0;
    for (int num : odd) {
        nums[index++] = num;
    }
    for (int num : even) {
        nums[index++] = num;
    }
}

int main() {
    int T;  // Number of test cases
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        vector<int> nums(N);
        
        // Input the array elements
        for (int i = 0; i < N; i++) {
            cin >> nums[i];
        }

        // Sort the array according to the problem statement
        sortOddEven(nums);

        // Output the sorted array
        for (int i = 0; i < N; i++) {
            cout << nums[i] << " ";
        }
        cout << endl;
    }

    return 0;
}

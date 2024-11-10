//Fruit Into Baskets
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int totalFruits(vector<int> &arr) {
    int n = arr.size();
    int max_len = 0;
    unordered_map<int, int> mpp;  // Tracks the count of each fruit type in the window
    
    int l = 0;  // Left boundary of the window
    
    for (int r = 0; r < n; r++) {
        mpp[arr[r]]++;  // Add the current fruit to the window

        // Shrink the window from the left if there are more than 2 types of fruits
        while (mpp.size() > 2) {
            mpp[arr[l]]--;
            if (mpp[arr[l]] == 0) {
                mpp.erase(arr[l]);  // Remove the fruit type from the map if its count is zero
            }
            l++;
        }

        // Update max_len if the window has at most 2 types of fruits
        max_len = max(max_len, r - l + 1);
    }
    
    return max_len;
}

int main() {
    // Example test case
    vector<int> arr = {3, 1, 2, 2, 2, 2};
    
    // Call the function
    int result = totalFruits(arr);
    
    // Output the result
    cout << "The maximum number of fruits that can be picked is: " << result << endl;

    return 0;
}

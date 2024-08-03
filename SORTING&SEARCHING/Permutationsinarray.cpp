#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isPossible(int k, vector<int> &arr1, vector<int> &arr2) {
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end(), greater<int>());
        int n=arr1.size();
        for (int i = 0; i <n; i++) {
            if (arr1[i] + arr2[i] < k) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    int k1 = 10;
    vector<int> arr1_1 = {2, 1, 3};
    vector<int> arr2_1 = {7, 8, 9};
    
    bool result1 = solution.isPossible(k1, arr1_1, arr2_1);
    cout << "Test Case 1: " << (result1 ? "True" : "False") << endl;
    
    return 0;
}

#include <vector>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> count_NGE(int n, vector<int>& arr, int queries, vector<int>& indices) {
        vector<int> count(n, 0);  // To store the count of greater elements to the right for each index
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[j] > arr[i]) {
                    count[i]++;
                }
            }
        }

        // Answer the queries using the precomputed counts
        vector<int> result;
        for (int i = 0; i < queries; i++) {
            result.push_back(count[indices[i]]);
        }
        
        return result;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> arr1 = {3, 4, 2, 7, 5, 8, 10, 6};
    vector<int> indices1 = {0, 5};
    vector<int> result1 = sol.count_NGE(arr1.size(), arr1, indices1.size(), indices1);
    for (int i : result1) {
        cout << i << " ";
    }
    cout << endl;  // Expected Output: 6 1

    // Test Case 2
    vector<int> arr2 = {1, 2, 3, 4, 1};
    vector<int> indices2 = {0, 3};
    vector<int> result2 = sol.count_NGE(arr2.size(), arr2, indices2.size(), indices2);
    for (int i : result2) {
        cout << i << " ";
    }
    cout << endl;  // Expected Output: 3 0

    return 0;
}

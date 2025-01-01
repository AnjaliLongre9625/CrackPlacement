#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        int n = arr.size();
        if (n < 2) {
            return -1; // Return -1 if there aren't enough elements.
        }
        
        int largest = INT_MIN, secondLargest = INT_MIN;

        // Iterate to find the largest and second largest
        for (int num : arr) {
            if (num > largest) {
                secondLargest = largest;
                largest = num;
            } else if (num > secondLargest && num != largest) {
                secondLargest = num;
            }
        }

        return secondLargest == INT_MIN ? -1 : secondLargest;
    }
};

int main() {
    vector<int> arr = {12, 35, 1, 10, 34, 1};
    Solution solution;
    int ans = solution.getSecondLargest(arr);
    if (ans != -1) {
        cout << "The second largest element is: " << ans << endl;
    } else {
        cout << "No second largest element exists." << endl;
    }
    return 0;
}

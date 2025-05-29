#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class KthLargest {
public:
    // Min-heap to store the top k largest elements seen so far.
    priority_queue<int, vector<int>, greater<int>> pq;// The smallest element in this heap is the kth largest overall.
    int A;// Variable to store the value of k

    KthLargest(int k, vector<int>& nums) {   // Constructor to initialize the class with k and the initial stream of numbers
        A = k;  // Save the kth position
        for (auto it : nums) {// Add all initial numbers to the min-heap
            pq.push(it);
        }
        while (pq.size() > A) {// If heap size exceeds k, remove the smallest elements to keep only top k
            pq.pop();
        }
    }
    
    int add(int val) { // Add a new value to the stream and return the kth largest element
        pq.push(val);  // Add new value to min-heap
        if (pq.size() > A) {// If heap size exceeds k, remove the smallest element
            pq.pop();
        }
        return pq.top();// The top of the min-heap is the kth largest element
    }
};

int main() {
    // Initialize KthLargest with k=3 and initial stream [4,5,8,2]
    vector<int> nums = {4, 5, 8, 2};
    KthLargest kthLargest(3, nums);

    // Perform add operations and print kth largest after each
    cout << kthLargest.add(3) << "\n";  // Output: 4
    cout << kthLargest.add(5) << "\n";  // Output: 5
    cout << kthLargest.add(10) << "\n"; // Output: 5
    cout << kthLargest.add(9) << "\n";  // Output: 8
    cout << kthLargest.add(4) << "\n";  // Output: 8

    return 0;
}

// Explanation:
// •	We maintain a min-heap (priority_queue with greater comparator) of size k.
// •	The heap stores the top k largest elements seen so far.
// •	The smallest element in the heap (top of min-heap) is the kth largest overall.
// •	On initialization, we push all numbers, then pop until the size is k.
// •	On adding a new element, push it; if size exceeds k, pop the smallest.
// •	The top of the heap is returned as the kth largest.

// Time Complexity:
// •	Initialization: O(N log k), where N = initial nums size
// •	Each add operation: O(log k)

// •	Space Complexity: O(k) for the heap


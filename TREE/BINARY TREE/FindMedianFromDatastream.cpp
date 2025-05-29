#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class MedianFinder {
    // Max heap for the left half
    priority_queue<int> maxh;

    // Min heap for the right half
    priority_queue<int, vector<int>, greater<int>> minh;

public:
    // Constructor
    MedianFinder() {}

    // Adds a number into the data structure
    void addNum(int num) {
        maxh.push(num);
        minh.push(maxh.top());
        maxh.pop();

        // Balance: maxh can have one more element than minh
        if (minh.size() > maxh.size()) {
            maxh.push(minh.top());
            minh.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if (minh.size() == maxh.size()) {
            return (maxh.top() + minh.top()) / 2.0;
        } else {
            return maxh.top();
        }
    }
};

// Driver code to test the class
int main() {
    MedianFinder mf;

    mf.addNum(1);
    mf.addNum(2);
    cout << "Median: " << mf.findMedian() << endl; // Output: 1.5

    mf.addNum(3);
    cout << "Median: " << mf.findMedian() << endl; // Output: 2

    mf.addNum(4);
    cout << "Median: " << mf.findMedian() << endl; // Output: 2.5

    return 0;
}
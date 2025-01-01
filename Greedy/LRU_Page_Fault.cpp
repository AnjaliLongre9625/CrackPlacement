#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int pageFaults(int N, int C, vector<int> pages) {
    vector<int> cache;  // Cache to store pages with a capacity of C
    int cnt = 0;        // Counter for page faults

    for (int i = 0; i < N; i++) {
        auto it = find(cache.begin(), cache.end(), pages[i]);

        // If page is not in cache (page fault)
        if (it == cache.end()) {
            cnt++;  // Increment page fault count

            // If cache is full, remove the least recently used page
            if (cache.size() == C) {
                cache.erase(cache.begin());
            }
        } else {
            // If page is in cache, remove it to update its position
            cache.erase(it);
        }

        // Add the current page to the end of the cache (most recently used)
        cache.push_back(pages[i]);
    }

    return cnt;  // Return total page faults
}

int main() {
    vector<int> pages = {1, 3, 0, 3, 5, 6};  // Page requests
    int N = pages.size();
    int C = 3;  // Cache capacity

    cout << "Page faults: " << pageFaults(N, C, pages) << endl;
    return 0;
}
        
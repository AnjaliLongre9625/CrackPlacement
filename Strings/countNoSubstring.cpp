#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    // Helper function to count the number of substrings with at most k distinct characters
    long long helper(string &s, int k){
        vector<int> freq(26, 0);   // Frequency array for characters 'a' to 'z'
        int left = 0;              // Left pointer of sliding window
        int distinctCount = 0;     // Number of distinct characters in current window
        long long cnt = 0;         // Count of substrings with at most k distinct characters
        
        // Expand the right pointer of the sliding window
        for (int i = 0; i < (int)s.size(); i++) {
            // If this character is new to the window, increase distinctCount
            if (freq[s[i] - 'a'] == 0) {
                distinctCount++;
            }
            freq[s[i] - 'a']++;
            
            // Shrink the window from left if distinctCount exceeds k
            while (distinctCount > k) {
                freq[s[left] - 'a']--;
                if (freq[s[left] - 'a'] == 0) {
                    distinctCount--;
                }
                left++;
            }
            // Add the number of valid substrings ending at i
            cnt += i - left + 1;
        }
        return cnt;
    }
    
    // Returns the number of substrings with exactly k distinct characters
    long long int substrCount(string s, int k) {
        // Number of substrings with exactly k distinct = 
        // substrings with at most k distinct - substrings with at most (k-1) distinct
        return helper(s, k) - helper(s, k - 1);
    }
};

int main() {
    Solution sol;
    string s2 = "abaaca";
    int k2 = 1;
    cout << "Output for test case 2: " << sol.substrCount(s2, k2) << endl; // Expected output: 7
    
    return 0;
}

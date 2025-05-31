#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        // Map of Roman numerals to their integer values
        unordered_map<char,int> mp = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int total = 0;
        // Iterate through the string
        for (int i = 0; i < (int)s.size(); i++) {
            // If current value is less than next value, subtract it
            // Otherwise, add it
            if (i + 1 < (int)s.size() && mp[s[i]] < mp[s[i + 1]]) {
                total -= mp[s[i]];
            } else {
                total += mp[s[i]];
            }
        }
        return total;
    }
};

int main() {
    Solution sol;

    // Test cases
    vector<string> testCases = {
        "III",    // 3
        "IV",     // 4
        "IX",     // 9
        "LVIII",  // 58
        "MCMXCIV",// 1994
        "MMXXV",  // 2025
        "XLII"    // 42
    };

    for (auto &tc : testCases) {
        cout << "Roman numeral: " << tc << " -> Integer: " << sol.romanToInt(tc) << endl;
    }

    return 0;
}

/*
Time Complexity:
- O(n), where n = length of input string s.
- We iterate through the string once.

Space Complexity:
- O(1), as the unordered_map size is fixed (7 Roman numerals).
- No extra space that grows with input size.
*/

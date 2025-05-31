#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mpp;
        
        for (auto x : strs) {
            string temp = x; // Store the original string
            sort(temp.begin(), temp.end()); // Sort the string
            mpp[temp].push_back(x); // Add the original string to  corresponding sorted key
        }
        
        for (auto it : mpp) {
            ans.push_back(it.second); // Collect all the grouped anagrams
        }
        
        return ans;
    }
};

int main() {
    Solution solution; // Create an instance of the Solution class
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"}; // Sample input
    vector<vector<string>> result = solution.groupAnagrams(strs); // Call the function

    // Print the grouped anagrams
    for (const auto& group : result) {
        cout << "[ ";
        for (const auto& str : group) {
            cout << str << " ";
        }
        cout << "]\n";
    }

    return 0;
}

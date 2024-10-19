#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int i, int j, const string &str) {
    while (i < j) {
        if (str[i] != str[j]) return false;
        i++;
        j--;
    }
    return true;
}

int f(int i, int n, const string &str, vector<int>& dp) {
    if (i == n) return 0; // Base case: if we've reached the end of the string
    if (dp[i] != -1) return dp[i]; // Return memoized result
    
    int mincost = INT_MAX;
    for (int j = i; j < n; j++) {
        if (isPalindrome(i, j, str)) {
            int cost = 1 + f(j + 1, n, str, dp); // 1 cut for this palindrome
            mincost = min(mincost, cost); // Minimize the cost
        }
    }
    
    return dp[i] = mincost; // Memoize the result
}

int palindromePartitioning(const string &str) {
    int n = str.size();
    vector<int> dp(n, -1);
    return f(0, n, str, dp) - 1; // Subtract 1 to get the number of cuts
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str; // Input the string for partitioning

    int cuts = palindromePartitioning(str); // Calculate minimum cuts
    cout << "Minimum number of cuts needed: " << cuts << endl; // Output the result

    return 0;
}

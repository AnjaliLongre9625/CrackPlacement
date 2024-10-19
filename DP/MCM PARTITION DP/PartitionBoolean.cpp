#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1000000007;

class Solution {
public:
    int f(int i, int j, int isTrue, string &expression, vector<vector<vector<ll>>> &dp) {
        if (i > j) return 0; // Invalid expression

        if (i == j) {
            // Base case: single character
            if (isTrue) return expression[i] == 't' ? 1 : 0; // 't' is True
            else return expression[i] == 'f' ? 1 : 0; // 'f' is False
        }

        // If already computed, return the stored value
        if (dp[i][j][isTrue] != -1) return dp[i][j][isTrue];

        ll ways = 0;

        // Loop through operators and divide the expression
        for (int ind = i + 1; ind <= j - 1; ind += 2) {
            ll lT = f(i, ind - 1, 1, expression, dp); // Ways to evaluate left part to true
            ll lF = f(i, ind - 1, 0, expression, dp); // Ways to evaluate left part to false
            ll rT = f(ind + 1, j, 1, expression, dp); // Ways to evaluate right part to true
            ll rF = f(ind + 1, j, 0, expression, dp); // Ways to evaluate right part to false

            // Apply the operator at expression[ind]
            if (expression[ind] == '&') { // AND operator
                if (isTrue) ways = (ways + (lT * rT) % mod) % mod;
                else ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lF * rF) % mod) % mod;
            } else if (expression[ind] == '|') { // OR operator
                if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lT * rT) % mod) % mod;
                else ways = (ways + (lF * rF) % mod) % mod;
            } else { // XOR operator
                if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod) % mod;
                else ways = (ways + (lF * rF) % mod + (lT * rT) % mod) % mod;
            }
        }

        // Store result in dp array
        return dp[i][j][isTrue] = ways;
    }

    bool parseBoolExpr(string expression) {
        int n = expression.size();
        vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, -1)));
        // Evaluate the expression with isTrue set to true
        return f(0, n - 1, 1, expression, dp) > 0; // If the expression evaluates to True
    }
};

// Example usage
int main() {
    Solution sol;
    string expression = "|(f,f,f,t)";
    cout << (sol.parseBoolExpr(expression) ? "true" : "false") << endl; // Expected output: true
    return 0;
}

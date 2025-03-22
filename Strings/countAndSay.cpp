#include <iostream>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1"; // Base case
        
        string say = countAndSay(n - 1); // Recursive call to get previous sequence
        string res = "";

        for (int i = 0; i < say.size(); i++) {
            char ch = say[i];  
            int cnt = 1;  

            // Count occurrences of consecutive characters
            for (; i < say.size() - 1 && say[i] == say[i + 1]; i++) {
                cnt++;
            }

            res += to_string(cnt) + ch; // Append count and character
        }
        
        return res;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    string result = sol.countAndSay(n);
    cout << "Count and Say Sequence for n = " << n << " is: " << result << endl;

    return 0;
}

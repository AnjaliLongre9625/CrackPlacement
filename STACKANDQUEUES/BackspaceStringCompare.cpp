class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<int> st1, st2;

        for (int i = 0; i < s.size(); i++) {
            st1.push(charAt(i));
            if (s[i] == "#") {
                st1.pop();
            }
        }
        for (int i = 0; i < t.size(); i++) {
            st2.push(charAt(i));
            if (t[i] == "#") {
                st2.pop();
            }
        }
        return (st1.top()==st2.top());
    }
};
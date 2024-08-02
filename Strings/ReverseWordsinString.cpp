#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    string reverseWords(string s){
        int i = 0;
        int n = s.size();
        string ans = "";

        while (i < n)
        {
            string temp = "";
            while (s[i] == ' ' && i < n)
            {
                i++;
            }
            while (s[i] != ' ' && i < n)
            {
                temp += s[i];
                i++;
            }
            if (temp.size() > 0)
            {
                if (ans.size() == 0)
                    ans = temp;
                else
                    ans = temp + " " + ans;
            }
        }
        return ans;
    }
};
int main(){
    Solution solution;
    string s= "Anjali is amazon intern girl";
    string result=solution.reverseWords(s);
    cout<<"Reverse Words in a String: "<<result<<endl;
    return 0;
}
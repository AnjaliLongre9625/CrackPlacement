#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
       string res="";
       for(int i=0;i<strs.size();i++){
          for(auto s:strs){
             if(s[i]!=strs[0][i]){
                 return res;
             }
         }
        res+=strs[0][i];
    } 
    return res; 
  }
int main() {
    vector<string> test1 = {"flo", "flow", "flight"};
    cout <<"longestCommonPrefix:"<<longestCommonPrefix(test1) << endl; // Output: "fl"
    return 0;
}
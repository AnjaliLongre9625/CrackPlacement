#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    long long helper(string &s,int k){
        vector<int>freq(26,0);
        int left=0;
        int distinctCount=0;
        long long cnt=0;
        
        for(int i=0;i<s.size();i++){
          if(freq[s[i]-'a']==0){
              distinctCount++;
          }
          freq[s[i]-'a']++;
          
          while(distinctCount>k){
            freq[s[left]-'a']--;
            if(freq[s[left]-'a']==0){
                distinctCount--;
            }
            left++;
          }
          cnt+=i-left+1;  
        }
        return cnt;
    }
    long long int substrCount (string s, int k) {
    	return  (helper(s,k)-helper(s,k-1));
    }
};
int main() {
    Solution sol;
    string s2 = "abaaca";
    int k2 = 1;
    cout << "Output for test case 2: " << sol.substrCount(s2, k2) << endl; // Output: 7
    
    return 0;
}
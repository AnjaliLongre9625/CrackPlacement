#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>st;
        vector<int> leftheight(n),rightheight(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()) 
                leftheight[i]=0;
            else 
                leftheight[i]=st.top()+1;
                st.push(i);
        }
        while(!st.empty()){
          st.pop();
         }
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()) rightheight[i]=n-1;
            else rightheight[i]=st.top()-1;
            st.push(i);
        }
        int maxA=0;
        for(int i=0;i<n;i++){
            maxA=max(maxA,heights[i]*(rightheight[i]-leftheight[i]+1));
        }
        return maxA;
    }
};
int main(){
    Solution solution;
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    int result=solution.largestRectangleArea(heights);
    cout<<"Largest Rectangle in Histogram"<<result<<endl;
    return 0;
}


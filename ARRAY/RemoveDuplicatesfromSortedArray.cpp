#include <bits/stdc++.h>
using namespace std;

//optimal
int removeDuplicates(vector<int>& nums) {
    int i=0;
    int n=nums.size();
    for(int j=1;j<n;j++){
      if(nums[i]!=nums[j]){
        nums[i+1]=nums[j];
        i++;
     }
    }return i+1;
}

int main(){
    
    vector<int> nums = {1,1,2,2,2,3,3};
    int l=removeDuplicates(nums);
    cout<<"removeDuplicates:"<<" ";
    for(int i=0;i<l;i++){
        cout<<nums[i]<<" ";
    }
        return 0;
}
//TC:O(n)
//SC:O(1)

// //brute
// int removeDuplicates(vector<int>& nums) {
//        if (nums.empty()) {
//             return 0;  // Edge case: If the array is empty, there are no duplicates to remove.
//         }
//        set<int>st;
//        int n=nums.size();
    
//        for(int i=0;i<n;i++){
//           st.insert(nums[i]);
//        } 
//        int index=0;
//        for(auto it:st){
//           nums[index]=it;
//           index++;
//        }return index;
//     }

// int main(){
//     int n=7;
//     vector<int> nums = {1,1,2,2,2,3,3};
//     int l=removeDuplicates(nums);
//     cout<<"removeDuplicates:"<<" ";
//     for(int i=0;i<l;i++){
//         cout<<nums[i]<<" ";
//     }
//         return 0;
// }
// //TC:O(n+nlogn);
// //SC:O(n);
// //Single pass through the vector (linear time) and in-place swaps (constant space)

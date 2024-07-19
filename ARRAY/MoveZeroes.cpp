#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& nums) {
      int n=nums.size();
      int j=0;
     
      for(int i=0;i<n;i++){
          if(nums[i]!=0){
            swap(nums[i],nums[j]);
            j++;
        }
       } 
    }
int main(){
    vector<int> nums = {0, 2, 1, 2, 0, 1};
    moveZeroes(nums);
    cout<<"MoveZeroes: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
//TC:O(n);
//SC:O(1);
//Single pass through the vector (linear time) and in-place swaps (constant space)

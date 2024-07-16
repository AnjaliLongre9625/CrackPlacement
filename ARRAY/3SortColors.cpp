#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& nums,int n) {
    int low=0,mid=0,high=n-1;

    while(mid<=high){
       if(nums[mid]==0){
          swap(nums[mid],nums[low]);
          low++;
          mid++;
       }
       else if(nums[mid]==1){
          mid++;
       }else{
          swap(nums[mid],nums[high]);
          high--;
       }
    }
}
int main(){
    int n=6;
    vector<int> nums = {0, 2, 1, 2, 0, 1};
    sortColors(nums,n);
    cout << "After sorting:" << endl;
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    cout <<endl;
    return 0;
}

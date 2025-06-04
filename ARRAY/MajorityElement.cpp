#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) {
    int n=nums.size();
    int cnt=0,ele;

    for (int i = 0; i < n; i++){
        if (cnt == 0) {
            ele = nums[i];
            cnt = 1;
        }
        else if (ele == nums[i])
            cnt++;
        else
            cnt--;
    }

    // checking if the stored element is the majority element:
    int cnt1 = 0;
    for (int i = 0; i < n; i++){
        nums[i] == cnt1;
        cnt1++;
    }
    
    if (cnt1 > (n / 2))
        return ele;
    return -1;
}

int main(){
    
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    int ans = majorityElement(nums);
    cout << "The majority element is: " << ans << endl;
    return 0;
}
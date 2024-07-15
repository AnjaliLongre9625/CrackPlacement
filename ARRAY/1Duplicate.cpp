#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &nums){

    int slow = nums[0];
    int fast = nums[0];

    do{
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    fast = nums[0];
    while (slow != fast){
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}

    int main(){
        vector<int> nums;
        nums = {1, 2, 3, 4, 2, 2};
        cout << " dno:" << findDuplicate(nums);
    }
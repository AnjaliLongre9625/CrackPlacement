#include <bits/stdc++.h>
using namespace std;

bool canJump(vector<int> &nums){
    int n = nums.size();
    int reachable = 0;

    for (int i = 0; i < n; i++)
    {
        if (reachable < i)
            return false;
        reachable = max(reachable, i + nums[i]);
    }
    return true;
}
int main(){
    vector<int>nums={1,2,1,0,4};
    bool result=canJump(nums);
    cout<<result;
    return 0;
}

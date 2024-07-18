#include <bits/stdc++.h>
using namespace std;
int minMoves2(vector<int> &nums){
    sort(nums.begin(),nums.end());
    int ans=0;
    int n=nums.size();
    for(int i=0;i<n;i++){
       int median=nums[n/2];
       ans+=abs(nums[i]-median);
    }
    return ans;
}
int main(){
vector<int> nums = {1,10,2,9};
    int ans1 = minMoves2(nums);
    cout << "Minimum Moves to Equal Array Elements II: " << ans1 << endl;
    return 0;
}


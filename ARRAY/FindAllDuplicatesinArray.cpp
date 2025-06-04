#include <bits/stdc++.h>
using namespace std;

vector<int> findDuplicates(vector<int> &nums){
    int n = nums.size();
    vector<int> result;
    
    for (int i = 0; i < n; i++){
        int indexToCheck = abs(nums[i]) - 1;
        if (nums[indexToCheck] < 0){
            result.push_back(abs(nums[i]));
        }
        else{
            nums[indexToCheck] = -nums[indexToCheck];
        }
    }
    return result;
}

int main(){
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> ans1 = findDuplicates(nums);

    cout << "Find All Duplicates in an Array:";
    for (int num : ans1) {
        cout << " " << num;
    }
    cout << endl;

    return 0;
}
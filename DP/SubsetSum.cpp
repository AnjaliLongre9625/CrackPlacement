#include <iostream>
#include <vector>
using namespace std;
class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return helper(n-1,sum,arr,dp);
    }
private:
    bool helper(int ind,int target,vector<int>&arr,vector<vector<int>>&dp){
        if(target==0) return true;
        if(ind==0) return arr[0]==target;
        if(dp[ind][target]!=-1) return dp[ind][target];
         
        bool take=false;
        bool nottake=helper(ind-1,target,arr,dp);
        
        if(arr[ind]<=target) take=helper(ind-1,target-arr[ind],arr,dp);
        return dp[ind][target]=take|| nottake;

        }
};
int main() {
    int n, sum;
    
    // Input: Size of array and the target sum
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the target sum: ";
    cin >> sum;

    Solution sol;
    if (sol.isSubsetSum(arr, sum)) {
        cout << "Subset with given sum exists!" << endl;
    } else {
        cout << "No subset with the given sum exists." << endl;
    }

    return 0;
}
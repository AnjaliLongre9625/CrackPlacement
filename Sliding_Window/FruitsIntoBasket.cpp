//Fruit Into Baskets
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int totalFruits(vector<int> &arr) {
        int n=arr.size();
        int max_len=0;
        unordered_map<int,int>mpp;
        
        int l=0,r=0;
        
        while(r<n){
            mpp[arr[r]]++;
            
            if(mpp.size()>2){
                mpp[arr[l]]--;
                if(mpp[arr[l]]==0) {
                    mpp.erase(arr[l]);
                }
             l++;
           }
        if(mpp.size()<=2) max_len=max(max_len,r-l+1);
          r++;
        }
        return max_len;
}

int main() {
    // Example test case
    vector<int> arr = {3, 1, 2, 2, 2, 2};
    
    // Call the function
    int result = totalFruits(arr);
    
    // Output the result
    cout << "The maximum number of fruits that can be picked is: " << result << endl;

    return 0;
}
scp /path/to/local/file anjali@DESKTOP-BQ29HIT
sftp anjali@DESKTOP-BQ29HIT@remote_ip
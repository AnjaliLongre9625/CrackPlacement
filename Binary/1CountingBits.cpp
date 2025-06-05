#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans(n+1,0);
        for(int i=1;i<=n;i++){
           ans[i]=ans[i/2]+(i%2);
        }
        return ans ;
    }
};

int main() {
    Solution sol;
    int n = 5;  // Example input
    vector<int> result = sol.countBits(n);

    cout << "The count of set bits from 0 to " << n << " is: ";
    for (int i = 0; i <= n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
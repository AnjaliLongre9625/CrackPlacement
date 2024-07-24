#include <bits/stdc++.h>
using namespace std;

int maxScore(vector<int>& cardPoints, int k) {
        
}

int main(){
    vector<int> cardPoints = {1,2,3,4,5,6,1};
    int k = 3; //output 12
    int ans = maxScore(cardPoints,k);
    cout << "Maximum Points You Can Obtain from Cards: " << ans << endl;
    return 0;
}

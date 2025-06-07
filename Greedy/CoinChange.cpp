#include <bits/stdc++.h>
using namespace std;

int minCoins(int coins[], int m, int sum){
    if (sum == 0) return 0;
    int cnt = 0;

    for (int i = m - 1; i >= 0; i--){
        while (sum > coins[i]){
            sum -= coins[i];
            cnt += 1;
        }
        
    }

    return cnt;
}

// Driver program to test above function
int main(){
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int m = sizeof(coins) / sizeof(coins[0]);
    int sum = 49;
    cout << "Minimum coins required is " << minCoins(coins, m, sum);
    return 0;
}
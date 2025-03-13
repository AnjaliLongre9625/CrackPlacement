#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
  
int main() {
    int n;
    cin >> n;  
    vector<long long> stcking(n);
    long long total = 0;
    
    
    for (int i = 0; i < n; i++) {
        cin >> stcking[i];
        total += stcking[i];
    }
    
    
    long long X = total / n;     
    int Riva = total % n;           
    
  
    sort(stcking.begin(), stcking.end());
    
    long long din = 0;
    
  
    for (int i = 0; i < n - Riva; i++) {
        if (stcking[i] > X)
        din += stcking[i] - X;
    }
    
    
    for (int i = n - Riva; i < n; i++) {
        if (stcking[i] > (X + 1))
        din += stcking[i] - (X + 1);
    }
    
    cout << din;
    return 0;
}
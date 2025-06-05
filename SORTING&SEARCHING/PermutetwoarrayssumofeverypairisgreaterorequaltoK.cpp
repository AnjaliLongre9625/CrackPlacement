#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool permute(int a[], int b[], int n, int k){
    sort(a, a + n);                        // sort in ascending
    sort(b, b + n, greater<int>());        // sort in descending
    for (int i = 0; i < n; i++){
        if (a[i] + b[i] == k)
            return true;
    }
    return false;
}

int main()
{
    int a[] = {2, 1, 3};
    int b[] = {7, 8, 9};
    int k = 10;
    int n=sizeof(a)/sizeof(a[0]); 

    permute(a, b, n, k) ? cout << "Yes" : cout << "No";
    return 0;
}
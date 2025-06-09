#include <bits/stdc++.h>
using namespace std;

int ceilSearch(int arr[], int low, int high, int x, int n) {
    int mid;      
    
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (arr[mid] == x) return mid;
        else if (arr[mid] > x) high = mid - 1;
        else low = mid + 1;
    }
    
    // Return low, but ensure it's within bounds
    return (low < n) ? low : -1;
}

int main() {
    int arr[] = {1, 2, 8, 10, 10, 12, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 8;
    int index = ceilSearch(arr, 0, n - 1, x, n);
    if (index == -1 || index >= n)
        printf("Ceiling of %d does not exist in the array", x);
    else
        printf("Ceiling of %d is %d", x, arr[index]);
    return 0;
}

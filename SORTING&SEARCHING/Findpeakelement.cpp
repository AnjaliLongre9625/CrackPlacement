#include <bits/stdc++.h>
using namespace std;
int findPeak(int arr[], int n) {
    if(n==0)return 0;
    if(n==1) return 0;
    if(arr[0]>arr[1]) return 0;
    if(arr[n-1]>arr[n-2]) return 0;

    int low=0,high=n-1; 

    while(low<high){
        int mid=(low+high)/2;

        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
            return mid;
        }

        else if(arr[mid]>arr[mid-1]){
            low=mid+1;
        }

        else{
            high=mid-1;
        }
    }

    return -1;
}

int main() {
    int arr[] = {1, 3, 20, 4, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Index of a peak point is: " << findPeak(arr, n);
    return 0;
}

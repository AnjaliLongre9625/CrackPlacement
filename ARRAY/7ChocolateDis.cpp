#include <bits/stdc++.h>
using namespace std;

long long findMinDiff(vector<long long> a, long long n, long long m){
      sort(a.begin(),a.end());
      
      long long min_diff=LLONG_MAX;
      
      for(int i=0;i+m-1<n;i++){
          int curr_diff=a[i+m-1]-a[i];
          if(curr_diff<min_diff){
              min_diff=curr_diff;
          }
      }
       return min_diff;
    }   

int main(){
     vector<long long> A1 = {3, 4, 1, 9, 56, 7, 9, 12};
    long long N1 = 8;
    long long M1 = 5;
    cout << "Minimum difference : " << findMinDiff(A1, N1, M1) << endl; 
    return 0;
}
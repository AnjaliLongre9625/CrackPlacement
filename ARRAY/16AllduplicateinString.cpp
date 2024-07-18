#include<bits/stdc++.h>
using namespace std;

void printDup(string str){
   int n=str.size();
   unordered_map<char ,int>count;
   for(int i=0;i<n;i++){
     count[str[i]]++;
   }
   for(auto it:count){
    if(it.second>1){
        cout << it.first << ", count = " << it.second<< "\n";
    }
  }
}

int main(){
    string strs="abbcadeeefa";
    printDup(strs);
    return 0;
}
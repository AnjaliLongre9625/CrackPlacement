#include <bits/stdc++.h>
using namespace std;

string addBinary(string a, string b){
    int alen = a.length();
    int blen = b.length();
    int carry = 0, i = 0;
    string ans = "";

    while (i < alen || i < blen || carry != 0){
        int x = 0;
        if (i < alen && a[alen - i - 1] == '1'){
            x = 1;
        }
        int y = 0;
        if (i < blen && b[blen - i - 1] == '1'){
            y = 1;
        }
        ans = to_string((x + y + carry) % 2) + ans;
        carry = (x + y + carry) / 2;
        i++;
    }
    return ans;
}
int main(){
    string a = "11";
    string b = "101";
    cout << "Add Binary numbers: " << addBinary(a, b) << endl;
    return 0;
}
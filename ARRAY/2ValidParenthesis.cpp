#include <bits/stdc++.h>
using namespace std;

bool isValid(string s) {
    int n=s.size();
    stack<char>st;
    for(int i=0;i<n;i++){
        if(s[i]=='(' || s[i]=='[' || s[i]== '{'){
            st.push(s[i]);
        }else{
            if(st.empty()) return false;
            char t=st.top();
            st.pop();
             if((s[i] == ')' && t != '(') ||
               (s[i] == ']' && t != '[') ||
               (s[i] == '}' && t != '{')) {
                return false;
               }
        }
    }
    if(st.empty()){
        return true;
    }
    return false;
}

int main(){
 string s="({})[]{()}";
 if(isValid(s))
        cout << "true" <<endl;
    else
        cout << "false" <<endl;
 return 0;
}
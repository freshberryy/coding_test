#include <bits/stdc++.h>
using namespace std;  

int main(){
    while(true){
        string s;
        getline(cin, s);
        if(s == ".") break;
        stack<char> stk;
        bool check = true;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ')'){
                if(stk.empty() || stk.top() == '['){
                    check = false;
                    break;
                }else stk.pop();
            }
            if(s[i] == ']'){
                if(stk.empty() || stk.top() == '('){
                    check = false;
                    break;
                }else stk.pop();
            }
            if(s[i] == '(')stk.push(s[i]);
            if(s[i] == '[')stk.push(s[i]);
        }
        if(check && stk.size() == 0) cout << "yes\n";
        else cout << "no\n";
    }
}
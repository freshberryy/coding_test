#include<bits/stdc++.h>
using namespace std;
unordered_map<char, char> mp = {
    {')', '('},
    {']', '['},
    {'}', '{'}
};
bool isValid(string s, int start){
    stack<char> stk;
    for(int i = 0; i < s.size(); i++){
        char c = s[(start + i) % s.size()];
        if(mp.count(c)){
            if(stk.empty() || stk.top() != mp[c]) return false;
            else stk.pop();
        }else stk.push(c);
    }
    return stk.empty();
}
int solution(string s){
    int ret = 0;
    for(int i = 0; i < s.size(); i++){
        ret += isValid(s, i);
    }
    return ret;
}
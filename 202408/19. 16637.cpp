#include <bits/stdc++.h>
using namespace std; //1
int n, ret = -1e9;
vector<char> opcode;
vector<int> number;
string s;
int oper(char a, int b, int c){
    if(a == '+') return b + c;
    if(a == '-') return b - c;
    if(a == '*') return b * c;
}
void go(int idx, int psum){
    if(idx == number.size() - 1){
        ret = max(ret, psum);
        return;
    }
    go(idx + 1, oper(opcode[idx], psum, number[idx + 1]));
    if(idx + 2 <= number.size() - 1){
        int tmp = oper(opcode[idx + 1], number[idx + 1], number[idx + 2]);
        go(idx + 2, oper(opcode[idx], psum, tmp));
    }
}
int main(){
    cin >> n >> s;
    for(int i = 0; i < n; i++){
        if(i % 2) opcode.push_back(s[i]);
        else number.push_back(s[i] - '0');
    }
    go(0, number[0]);
    cout << ret;
}
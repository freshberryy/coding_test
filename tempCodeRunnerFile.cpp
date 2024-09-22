#include<bits/stdc++.h>
using namespace std;
string s;
int ret;
int ton(string str){
    int ret = 0;
    reverse(str.begin(), str.end());
    for(int i = 0,j = 0; i < str.size(); i++, j++){
        ret += (str[i] - '0') * pow(2, j);
    }
    return ret;
}
int main(){
    cin >> s;
    int n = ton(s);
    for(int i = 0; i < 3; i++){
        n ^= (1 << i);
        ret = max(ret, n);
        n ^= (1 << i);
    }
    cout << ret;
}

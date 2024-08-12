#include<bits/stdc++.h>
using namespace std;
int n;
string s;
char a[68][68];
string go(int y, int x, int len){
    if(len == 1) return string(1, a[y][x]);
    string ret = "";
    char b = a[y][x];
    for(int i = y; i < y + len; i++){
        for(int j = x; j < x + len; j++){
            if(b != a[i][j]){
                ret += "(";
                ret += go(y, x, len / 2);
                ret += go(y, x + len / 2, len / 2);
                ret += go(y + len / 2, x, len / 2);
                ret += go(y + len / 2, x + len / 2, len / 2);
                ret += ")";
                return ret;
            }
        }
    }
    return string(1, b); //모든 좌표값이 동일한 경우
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < n; j++){
            a[i][j] = s[j];
        }
    }
    cout << go(0, 0, n);
}
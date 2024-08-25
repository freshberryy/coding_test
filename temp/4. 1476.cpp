#include<bits/stdc++.h>
using namespace std;
int n, m, x;
bool broken[10];
int possible(int c){
    if(c == 0){
        if(broken[0]) return 0;
        else return 1;
    }
    int len = 0;
    while(c > 0){
        if(broken[c % 10]) return 0;
        len += 1;
        c /= 10;
    }
    return len;
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> x;
        broken[x] = true;
    }
    int ret = n - 100;
    if(ret < 0) ret = abs(ret);
    for(int i = 0; i < 1000000; i++){
        int c = i;
        int len = possible(c);
        if(len > 0){
            int press = c - n;
            if(press < 0) press = abs(press);
            ret = min(ret, len + press);
        }
    }
    cout << ret;
}
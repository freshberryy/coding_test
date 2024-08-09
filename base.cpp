#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int main(){
    int n = 1000;
    int b = 16;
    while(n > 0){
        v.push_back(n % b);
        n /= b;
    }
    reverse(v.begin(), v.end());
    for(int a : v){
        if(a >= 10) cout << char(a + 55);
        else cout << a;
    }
}
#include<bits/stdc++.h>
using namespace std;
string s;
int cnt[26];
int main(){
    cin >> s;
    for(char i : s){
        cnt[i - 'a']++;
    }
    for(int i = 0; i < 26; i++) cout << cnt[i] << " ";
}
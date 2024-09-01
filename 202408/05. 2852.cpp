#include <bits/stdc++.h>
using namespace std;  //2
int n, team, a, b, amin, bmin;
string s, pre;
string print(int a){
    string h = "00" + to_string(a / 60);
    string m = "00" + to_string(a % 60);
    return h.substr(h.size() - 2, 2) + ":" + m.substr(m.size() - 2, 2);
}
int cti(string s){
    return atoi(s.substr(0, 2).c_str()) * 60 + atoi(s.substr(3, 2).c_str());
}
void go(int &min, string s){
    min += cti(s) - cti(pre);
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> team >> s;
        if(a > b) go(amin, s);
        if(a < b) go(bmin, s);
        team == 1 ? a++ : b++;
        pre = s;
    }
    string ss = "48:00";
    if(a > b) go(amin, ss);
    if(a < b) go(bmin, ss);
    cout << print(amin) << "\n";
    cout << print(bmin) << "\n";
}
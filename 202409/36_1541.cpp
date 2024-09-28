#include<bits/stdc++.h>
using namespace std;
int ret;
string s;
vector<string> split(string &input, string del){
    vector<string> ret;
    int s = 0; int e = input.find(del);
    while(e != string::npos){
        ret.push_back(input.substr(s, e - s));
        s = e + del.size();
        e = input.find(del, s);
    }
    ret.push_back(input.substr(s));
    return ret;
}
int go(string s){
    int sum = 0;
    vector<string> v = split(s, "+");
    for(int i = 0; i < v.size(); i++){
        sum += stoi(v[i]);
    }
    return sum;
}
int main(){
    cin >> s;
    vector<string> v = split(s, "-");
    for(int i = 0; i < v.size(); i++){
        int tmp = go(v[i]);
        if(i == 0) ret += tmp;
        else ret -= tmp;
    }
    cout << ret;
}

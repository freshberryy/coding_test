#include<bits/stdc++.h>
using namespace std;
string s;
int con, vow;
bool isVowel(int idx){
    return (idx == 'a' || idx == 'e' || idx == 'i' || idx == 'o' || idx == 'u');
}
int main(){
    while(true){
        cin >> s;
        if(s == "end")break;
        con = vow = 0;
        bool flag = 0;
        bool is_include_v = 0;
        int prev = -1;
        for(int i = 0; i < s.size(); i++){
            int idx = s[i];
            if(isVowel(idx)){
                vow++;
                con = 0;
                is_include_v = 1;
            }else{
                vow = 0;
                con++;
            }if(vow == 3 || con == 3) flag = 1;
            if(i >= 1 && (prev == idx) && (idx != 'e' && idx != 'o')){
                flag = 1;
            }
            prev = idx;
        }
        if(!is_include_v) flag = 1;
        if(flag) cout << "<" << s << ">" << " is not acceptable.\n";
        else cout << "<" << s << ">" << " is acceptable.\n";
    }
}

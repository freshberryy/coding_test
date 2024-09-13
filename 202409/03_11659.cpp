#include<bits/stdc++.h>
using namespace std;
int s[100004], no, quiz, tmp, i, j;
int main(){
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(0);
    cin >> no >> quiz;
    for(int i = 1; i <= no; i++){
        cin >> tmp;
        s[i] = s[i - 1] + tmp;
    }
    for(int k = 0; k < quiz; k++){
        cin >> i >> j;
        cout << s[j] - s[i - 1] << "\n";
    }
}
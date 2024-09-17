#include<bits/stdc++.h>
using namespace std;
//couting sort
int n, cnt[10004], number;
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> number;
        cnt[number]++;
    }
    for(int i = 0; i <= 10000; i++){
        if(cnt[i]){
            for(int j = 0; j < cnt[i]; j++){
                cout << i << "\n";
            }
        }
    }
}
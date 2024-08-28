#include <bits/stdc++.h>
using namespace std;  //1
int n, m, a[15004], cnt;
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i] + a[j] == m) cnt++;
        }
    }
    cout << cnt;
}
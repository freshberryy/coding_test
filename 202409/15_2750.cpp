#include<bits/stdc++.h>
using namespace std;
//bubble sort
int n, a[1004];
int main(){
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1 - i; j++){
            if(a[j] > a[j + 1]) swap(a[j], a[j + 1]);
        }
    }
    for(int i = 0; i < n; i++){
        cout << a[i] << "\n";
    }
}
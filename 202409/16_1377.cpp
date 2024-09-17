#include<bits/stdc++.h>
using namespace std;
int n, ret;
int main(){
    cin >> n;
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++){
        ret = max(ret, a[i].second - i);
    }
    cout << ret + 1;
}
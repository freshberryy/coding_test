#include <bits/stdc++.h>
using namespace std;
int n, a[1000004], o[1000004];
stack<int> s;
int main(){
    cin >> n;
    memset(o, -1, sizeof(o));
    for(int i = 0; i < n; i++){
        cin >> a[i];
        while(s.size() && a[s.top()] < a[i]){
            o[s.top()] = a[i];
            s.pop();
        }
        s.push(i);
    }
    for(int i = 0; i < n; i++){
        cout << o[i] << " ";
    }
}


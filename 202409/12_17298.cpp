#include<bits/stdc++.h>
using namespace std;
int const ee = 1000004;
int n, a[ee], o[ee];
stack<int> s;
int main(){
    memset(o, -1, sizeof(o));
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        while(s.size() && a[s.top()] < a[i]){
            o[s.top()] = a[i];
            s.pop();
        }
        s.push(i);
    }
    for(int i = 0; i < n; i++) cout << o[i] << " ";
}
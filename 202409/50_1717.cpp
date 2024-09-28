#include <bits/stdc++.h>
using namespace std;
int n, m, parent[1000004];

int find(int a){
    if(a == parent[a]) return a;
    else return parent[a] = find(parent[a]);
}

void unite(int a, int b){
    a = find(a); b = find(b);
    if(a != b) parent[b] = a;
}

bool sameset(int a, int b){
    a = find(a); b = find(b);
    if(a == b) return 1;
    else return 0;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); 
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 0; i <= n; i++){
        parent[i] = i;
    }
    for(int i = 0; i < m; i++){
        int q, a, b;
        cin >> q >> a >> b;
        if(q == 0) unite(a, b);
        else{
            if(sameset(a, b)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
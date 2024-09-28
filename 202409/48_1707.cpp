#include <bits/stdc++.h>
using namespace std;
int n, check[20004], visited[20004], a, b;
vector<int> adj[20004];
bool iseven = true;
void dfs(int here){
    visited[here] = 1;
    for(int there : adj[here]){
        if(!visited[there]){
            check[there] = (check[here] + 1) % 2;
            dfs(there);
        }else if(check[here] == check[there]) iseven = false;
    }
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int v, e;
        cin >> v >> e;
        for(int j = 0; j < e; j++){
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for(int j = 1; j <= v; j++){
            if(iseven) dfs(j);
            else break;
        }
        if(iseven) cout << "YES" << "\n";
        else cout << "NO" << "\n";
        for(int i = 0; i <= v; i++){
            adj[i].clear();
            visited[i] = 0;
            check[i] = 0;
        }
        iseven = true;
    }
}

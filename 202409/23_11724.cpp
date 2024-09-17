#include<bits/stdc++.h>
using namespace std;
int n, m, u, v, visited[1004], cnt;
vector<int> adj[1004];
void dfs(int here){
    visited[here] = 1;
    for(int there : adj[here]){
        if(!visited[there]) dfs(there);
    }
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            cnt++;
            dfs(i);
        }
    }
    cout << cnt;
}
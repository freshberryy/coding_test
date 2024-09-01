#include <bits/stdc++.h>
using namespace std; //2
int n, m, ret, visited[10004], a, b, arr[10004];
vector<int> adj[10004];
int dfs(int here){
    visited[here] = 1;
    int ret = 1;
    for(int there : adj[here]){
        if(visited[there]) continue;
        ret += dfs(there);
    }
    return ret;
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        adj[b].push_back(a);
    }
    for(int i = 1; i <= n; i++){
        memset(visited, 0, sizeof(visited));
        arr[i] = dfs(i);
        ret = max(ret, arr[i]);
    }
    
    for(int i = 1; i <= n; i++){
        if(ret == arr[i]){
            cout << i << " ";
        }
    }
}


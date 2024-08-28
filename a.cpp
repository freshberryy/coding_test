#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, visited[10004], cnt[10004], mx;
vector<int> adj[10004];

int dfs(int here){
    memset(visited, 0, sizeof(visited));
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
    for(int i = 0; i < n; i++){
        
        cnt[i] = dfs(i);
        mx = max(mx, cnt[i]);
    }
    for(int i = 0; i < n; i++){
        if(cnt[i] == mx) cout << i << " ";
    }
    
}
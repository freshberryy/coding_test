#include<bits/stdc++.h>
using namespace std;
int n, m, v, a, b, visited[1004];
vector<int> adj[1004];
void dfs(int here){
    visited[here] = 1;
    cout << here << " ";
    for(int there : adj[here]){
        if(!visited[there]){
            dfs(there);
        }
    }
}
void bfs(int here){
    visited[here] = 1;
    queue<int> q;
    q.push(here);
    while(q.size()){
        int now = q.front();
        q.pop();
        cout << now << " ";
        for(int there : adj[now]){
            if(visited[there])continue;
            visited[there] = 1;
            q.push(there);
        }
    }
}
int main(){
    cin >> n >> m >> v;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1; i <= n; i++){
        sort(adj[i].begin(), adj[i].end());
    }
    dfs(v);
    memset(visited, 0, sizeof(visited));
    cout << "\n";
    bfs(v);
}
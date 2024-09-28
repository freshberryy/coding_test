#include <bits/stdc++.h>
using namespace std;
int n, m, k, x, visited[300004], a, b;
vector<int> adj[300004];
vector<int> ret;
void bfs(int here){
    visited[here] = 1;
    queue<int> q;
    q.push(here);
    while(q.size()){
        int here = q.front();
        q.pop();
        for(int there : adj[here]){
            if(visited[there] != -1)continue;
            visited[there] = visited[here] + 1;
            q.push(there);
        }
    }
}
int main(){
    cin >> n >> m >> k >> x;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        adj[a].push_back(b);
    }
    memset(visited, -1, sizeof(visited));
    bfs(x);
    for(int i = 1; i <= n;i++){ //1-based 주의
        if(visited[i] - 1== k) ret.push_back(i);
    }
    if(ret.empty()) cout << -1;
    for(int i : ret) cout << i << "\n";
}
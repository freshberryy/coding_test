#include<bits/stdc++.h>
using namespace std;
int n, m, visited[2004], a, b;
bool arrive = false;
vector<int> adj[2004];
void dfs(int here, int depth){
    if(depth == 5 || arrive){
        arrive = 1;
        return;
    }
    visited[here] = 1;
    for(int there : adj[here]){
        if(!visited[there]){
            dfs(there, depth + 1);
        }
    }
    visited[here] = 0;
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 0; i < n; i++){
        dfs(i, 1);
        if(arrive)break;
    }
    if(arrive) cout << 1;
    else cout << 0;
}
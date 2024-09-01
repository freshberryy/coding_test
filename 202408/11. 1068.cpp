#include <bits/stdc++.h>
using namespace std;  //2
int n, par, root, del;
vector<int> adj[54];
int dfs(int here){
    int ret = 0;
    int child = 0;
    for(int there : adj[here]){
        if(there == del)continue;
        ret += dfs(there);
        child++;
    }
    if(child == 0) return 1;
    return ret;
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> par;
        if(par == -1) root = i;
        else adj[par].push_back(i);
    }
    cin >> del;
    if(del == root){
        cout << 0;
        return 0;
    }
    cout << dfs(root) << "\n";
    return 0;
}
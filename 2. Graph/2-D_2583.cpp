#include<bits/stdc++.h>
using namespace std;
int const dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
int n, m, k, a, b, c, d, arr[104][104], visited[104][104], cnt;
vector<int> v;
int dfs(int y, int x){
    int ret = 1;
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
        if(arr[ny][nx] == 0 && !visited[ny][nx]){
            ret += dfs(ny, nx);
        }
    }
    return ret;
}
int main(){
    cin >> n >> m >> k;
    while(k--){
        cin >> a >> b >> c >> d;
        for(int i = b; i < d; i++){
            for(int j = a; j < c; j++){
                arr[i][j] = 1;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == 0 && !visited[i][j]){
                v.push_back(dfs(i, j));
            }
        }
    }
    sort(v.begin(), v.end());
    cout << v.size() << "\n";
    for(int it : v) cout << it << " ";
}
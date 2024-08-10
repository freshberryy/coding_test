#include<bits/stdc++.h>
using namespace std;
int const dy[] = {-1, 0, 1, 0};
int const dx[] = {0, 1, 0, -1};
int t, n, m, k, x, y, a[54][54], visited[54][54];
void dfs(int y, int x){
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
        if(a[ny][nx] == 1 && !visited[ny][nx])dfs(ny, nx);
    }
}
int main(){
    cin >> t;
    while(t--){
        int ret = 0;
        memset(visited, 0, sizeof(visited));
        memset(a, 0, sizeof(a));
        cin >> m >> n >> k;
        while(k--){
            cin >> x >> y;
            a[y][x] = 1;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j] == 1 && !visited[i][j]){
                    dfs(i, j);
                    ret++;
                }
            }
        }
        cout << ret << "\n";
    }
}
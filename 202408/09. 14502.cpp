#include <bits/stdc++.h>
using namespace std;  //1
int const dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
vector<pair<int, int>> virus, wall;
int a[12][12], visited[12][12], n, m, ret;

void dfs(int y, int x){
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
        if(a[ny][nx] == 0 && !visited[ny][nx])dfs(ny, nx);
    }
}

int solve(){
    memset(visited, 0, sizeof(visited));
    for(auto it : virus){
        dfs(it.first, it.second);
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 0 && !visited[i][j])cnt++;
        }
    }
    return cnt;
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            if(a[i][j] == 0)wall.push_back({i, j});
            if(a[i][j] == 2)virus.push_back({i, j});
        }
    }
    int ee = wall.size();
    for(int i = 0; i < ee; i++){
        for(int j = i + 1; j < ee; j++){
            for(int k = j + 1; k < ee; k++){
                a[wall[i].first][wall[i].second] = 1;
                a[wall[j].first][wall[j].second] = 1;
                a[wall[k].first][wall[k].second] = 1;
                ret = max(ret, solve());
                a[wall[i].first][wall[i].second] = 0;
                a[wall[j].first][wall[j].second] = 0;
                a[wall[k].first][wall[k].second] = 0;
            }
        }
    }
    cout << ret;
}
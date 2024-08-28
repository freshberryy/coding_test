#include <bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0}; 
const int dx[] = {0, 1, 0, -1};
int n, m, visited[54][54], ret;
char a[54][54];
void bfs(int y, int x){
    visited[y][x] = 1;
    queue<pair<int, int>> q;
    q.push({y, x});
    while(q.size()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
            if(a[ny][nx] == 'W' || visited[ny][nx])continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
            ret = max(ret, visited[ny][nx]);
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            memset(visited, 0, sizeof(visited));
            if(a[i][j] == 'L') bfs(i, j);
        }
    }
    cout << ret - 1;
}


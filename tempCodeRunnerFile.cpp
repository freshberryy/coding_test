#include<bits/stdc++.h>
using namespace std;
int const dy[] = {-1, 0, 1, 0};
int const dx[] = {0, 1, 0, -1};
int n, m, a[104][104], visited[104][104], y, x;
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%1d", &a[i][j]);
        }
    }
    queue<pair<int, int>> q;
    visited[0][0] = 1;
    q.push({0, 0});
    while(q.size()){
        tie(y, x) = q.front();
        q.pop();
        for(int i = 0; i < n; i++){
            int ny = y + dy[i]; 
            int nx = x + dx[i]; 
            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if(a[ny][nx] == 0 || visited[ny][nx])continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }
    printf("%d", visited[n - 1][m - 1]);

}
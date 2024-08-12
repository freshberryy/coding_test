#include<bits/stdc++.h>
using namespace std;
int const dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
int n, a[104][104], visited[104][104], ret = 1, cnt;
void dfs(int y, int x, int d){
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= n)continue;
        if(!visited[ny][nx] && a[ny][nx] > d)dfs(ny, nx, d);
    }
}

int main(){
    cin >> n; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    for(int d = 1; d < 101; d++){
        memset(visited, 0, sizeof(visited));
        cnt = 0;
        for(int j = 0; j < n; j++){
            for(int h = 0; h < n; h++){
                if(a[j][h] > d && !visited[j][h]){
                    dfs(j, h, d);
                    cnt++;
                }
            }
        }
        ret = max(ret, cnt);
    }
    cout << ret;
}

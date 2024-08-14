#include<bits/stdc++.h>
using namespace std;
int const dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1}, INF = 1e9;
int n, m,fire[1004][1004], person[1004][1004], sy, sx, y, x,ret;;
char a[1004][1004];
int main(){
    queue<pair<int, int>> q;
    fill(&fire[0][0], &fire[0][0] + 1004 * 1004, INF);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            if(a[i][j] == 'F'){
                fire[i][j] = 1;
                q.push({i, j});
            }else if(a[i][j] == 'J'){
                sy = i;
                sx = j;
            }
        }
    }
    while(q.size()){
        tie(y, x) = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
            if(fire[ny][nx] != INF || a[ny][nx] == '#')continue;
            fire[ny][nx] = fire[y][x] + 1;
            q.push({ny, nx});
        }
    }
    person[sy][sx] = 1;
    q.push({sy, sx});
    while(q.size()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        if(y == 0 || x == 0 || y == n - 1 || x == m - 1){
            ret = person[y][x];
            break;
        }
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
            if(person[ny][nx] || a[ny][nx] == '#')continue;
            if(fire[ny][nx] <= person[y][x] + 1)continue;
            person[ny][nx] = person[y][x] + 1;
            q.push({ny, nx});
        }
    }
    if(ret) cout << ret << "\n";
    else cout << "IMPOSSIBLE \n";
}
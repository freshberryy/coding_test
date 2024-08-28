#include <bits/stdc++.h>
using namespace std;
const int dy[]={-1,0,1,0};
const int dx[] ={0,1,0,-1}; 
const int INF = 1e9;
int n, m, visited_fire[1004][1004], visited_hoon[1004][1004], ret, y, x;
char a[1004][1004];

int main(){
    cin >> n >> m;
    fill(&visited_fire[0][0], &visited_fire[0][0] + 1004 * 1004, INF);
    queue<pair<int, int>> q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            if(a[i][j] == 'F'){
                q.push({i, j});
                visited_fire[i][j] = 1;
            }
            if(a[i][j] == 'J'){
                y = i; x = j;
            }
        }
    }
    while(q.size()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
            if(visited_fire[ny][nx] != INF || a[ny][nx] == '#')continue;
            visited_fire[ny][nx] = visited_fire[y][x] + 1;
            q.push({ny, nx});
        }
    }
    visited_hoon[y][x] = 1;
    q.push({y, x});
    while(q.size()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        if(y == n - 1 || x == m - 1 || y == 0 || x == 0){
            ret = visited_hoon[y][x];
            break;
        }
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
            if(visited_hoon[ny][nx] || a[ny][nx] == '#') continue;
            if(visited_fire[ny][nx] <= visited_hoon[y][x] + 1)continue;
            visited_hoon[ny][nx] = visited_hoon[y][x] + 1;
            q.push({ny, nx});
        }
    }
    if(ret) cout << ret;
    else cout << "IMPOSSIBLE \n";
}
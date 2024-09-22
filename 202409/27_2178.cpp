#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, a[104][104], visited[104][104];
string s;
queue<pair<int, int>> q;
void bfs(int y, int x){
    visited[y][x] = 1;
    q.push({y, x});
    while(q.size()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
            if(a[ny][nx] == 0 || visited[ny][nx])continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }
}
int main(){
    cin >>n >> m;
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < s.size(); j++){
            a[i][j] = s[j] - '0';
        }
    }
    bfs(0, 0);
    cout << visited[n - 1][m - 1];
}
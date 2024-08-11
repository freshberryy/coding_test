#include<bits/stdc++.h>
using namespace std;
int n, l, r, a[54][54], visited[54][54], cnt, sum;
vector<pair<int, int>> v;
int const dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
void dfs(int y, int x, vector<pair<int, int>> &v){
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx])continue;
        if(abs(a[ny][nx] - a[y][x]) >= l && abs(a[ny][nx] - a[y][x]) <= r){
            visited[ny][nx] = 1;
            v.push_back({ny, nx});
            sum += a[ny][nx];
            dfs(ny, nx, v);
        }
    }
}
int main(){
    cin >> n >> l >> r;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    while(true){
        memset(visited, 0, sizeof(visited));
        bool flag = false;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(!visited[i][j]){
                    v.clear();
                    visited[i][j] = 1;
                    v.push_back({i, j});
                    sum = a[i][j];
                    dfs(i, j, v);
                    if(v.size() == 1) continue;
                    for(auto i : v){
                        a[i.first][i.second] = sum / v.size();
                        flag = true;
                    }
                }
            }
        }
        if(!flag) break;
        else cnt++;
    }
    cout << cnt;
}
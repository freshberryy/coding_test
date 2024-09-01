#include <bits/stdc++.h>
using namespace std; //1
const int dy[]={-1,0,1,0};
const int dx[] ={0,1,0,-1}; 
int n, l, r, a[54][54], visited[54][54], pop, cnt;
vector<pair<int, int>> v;
void dfs(int y, int x){
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx]) continue;
        if (abs(a[ny][nx] - a[y][x]) >= l && abs(a[ny][nx] - a[y][x]) <= r){
            pop += a[ny][nx];
            v.push_back({ny, nx});
            dfs(ny, nx);

        }
    }
}
int main(){
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
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
                    v.push_back({i, j});
                    pop = a[i][j];
                    dfs(i, j);
                    if(v.size() == 1) continue;
                    for(auto i : v){
                        a[i.first][i.second] = pop / v.size();
                        flag = true;
                    }
                }
            }
        }
        if(!flag) break;
        cnt++;
    }
    cout << cnt;
}
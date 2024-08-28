#include <bits/stdc++.h>
using namespace std;  //1
int dy[] = {-1,0,1,0}, dx[] = {0,1,0,-1};
int a[104][104], visited[104][104];
int n, m, meltingTime, lastNumber;
vector<pair<int, int>> v;
void go(int y, int x){
    visited[y][x] = 1;
    if(a[y][x] == 1){
        v.push_back({y, x});
        return;
    }
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx])continue;
        go(ny, nx);
    }
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    while(true){
        memset(visited, 0, sizeof(visited));
        v.clear();
        go(0, 0);
        lastNumber = v.size();
        for(auto i : v){
            a[i.first][i.second] = 0;
        }
        bool flag = false;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j] == 1) flag = true;
            }
        }
        meltingTime++;
        if(!flag) break;
    }
    cout << meltingTime << "\n" << lastNumber;
}
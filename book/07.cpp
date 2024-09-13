#include<bits/stdc++.h>
using namespace std;
bool visited[11][11][4];
int const dy[] = {-1, 0, 1, 0};
int const dx[] = {0, 1, 0, -1};
int todir(char dir){
    if(dir == 'U') return 0;
    else if(dir == 'R') return 1;
    else if(dir == 'D') return 2;
    else return 3;
}
bool check(int y, int x){
    return (y < 0 || x < 0 || y >10 || x > 10);
}
int opposite_dir(int dir){
    return (dir + 2) % 4;
}
int solution(string dirs){
    int ret = 0;
    int y = 5, x = 5;
    for(char c : dirs){
        int dir = todir(c);
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if(check(ny, nx)) continue;
        if(visited[y][x][dir] == false){
            visited[y][x][dir] = true;
            visited[ny][nx][opposite_dir(dir)] = true;
            ret++;
        }
        y = ny;
        x = nx;
    }
    return ret;
}
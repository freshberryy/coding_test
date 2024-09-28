/*달팽이 문제에서는 정답을 저장할 별도의 이차원 배열을 활용한다. 같은 방향으로 계속 진행하다가 방향을 틀어야 하는 조건은 현재 방향으로 더 갔을 때 격자를 벗어나게 되거나 혹은 그곳에 이미 방문했던 적이 있어서 숫자가 이미 적혀 있는 경우이다. 즉 같은 방향으로 계속 진행하기 위해서는 (ny, nx)가 직사각형 안에 들어오면서 그 위치에 방문했던 적이 없었어야 한다.
case1. 그 다음 위치가 격자를 벗어나지 않는지: isin 사용
case2. 이미 방문한 게 아닌지: visited가 0인지를 확인*/
#include <bits/stdc++.h>
using namespace std;
int const dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
int n = 4, visited[4][4], dir = 1;
bool isin(int ny, int nx){
    if(ny < 0 || nx < 0 || ny >= n || nx >= n) return false;
    return 1;
}
int main(){
    int y = 0, x = 0; //시작점
    
    //시작점에 초기값 
    visited[y][x] = 1;

    //n*n번 진행
    for(int i = 2; i <= n * n; i++){
        //nynx 선언
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        //검증 후 ny, nx 갱신
        if(!isin(ny, nx) || visited[ny][nx] != 0){
            dir = (dir + 1) % 4;
            ny = y + dy[dir];
            nx = x + dx[dir];
        }
        //y, x 갱신
        y = ny; x = nx;
        visited[y][x] = i;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cout << visited[i][j] << " ";
        cout << endl;
    }
}

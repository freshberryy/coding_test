#include <bits/stdc++.h>
using namespace std;
//문자에 따른 명령 2
int const dy[] = {0, -1, 0, 1}, dx[] = {1, 0, -1, 0};  //일반 좌표계에서 offset:동남서북
int n, x, y, dir  = 3;
string s;
int where(char c){
    if(c == 'S') return 0;
    if(c == 'E') return 1;
    if(c == 'N') return 2;
    if(c == 'W') return 3;
}
int main(){
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'L') dir = (dir + 3) % 4;  // 왼쪽 90도 회전
        else if(s[i] == 'R') dir = (dir + 1) % 4; // 오른쪽 90도 회전
        else{
            y += dy[dir];
            x += dx[dir];
        }
    }
    cout << x <<" " << y;
}
/*ny, nx를 선언하는 경우: 원래의 y, x값을 유지하면서 새로운 좌표를 계산한다. 예를 들어 이동하기 전에 다음 좌표를 미리 계산하고, 그 좌표가 격자 안에 있는지, 또는 벽이나 장애물이 있는지 확인한 후 실제로 이동할지 결정한다. 즉 실제 좌표에 영향을 주지 않으면서 새로운 좌표를 테스트할 수 있다. 
nynx 선언 -> 검증 후 nynx 갱신 -> y, x 갱신*/
/*  int ny = y + dy[dir];
    int nx = x + dx[dir];
    if(isin(ny, nx)) {
        // 좌표가 유효하면 이동
        y = ny;
        x = nx;
    }
*/

/*y+=, x+=처럼 현재 좌표를 즉시 업데이트하는 경우: 방향을 결정하고 바로 그 위치로 디오한다. 이때는 다음 좌표를 확인하기 전에 이미 좌표가 변경되므로, 조건 확인 전 이동해버린다. 따라서 이동한 이후에 그 위치가 유효하지 않거나 벽에 부딪힌다면 다시 되돌려야 한다.*/
/*
    y += dy[dir];
    x += dx[dir];
    if(!isin(y, x)) {
        // 좌표가 유효하지 않으면 다시 되돌리는 작업이 필요
        y -= dy[dir];
        x -= dx[dir];
    }

*/


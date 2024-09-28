#include <bits/stdc++.h>
using namespace std;
//작은 구슬의 이동
int const dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1}; //2차원 행렬에서의 offset: 북동남서
int n, t, r, c, a[54][54];
char d;
int Dir(char c){
    if(c == 'U') return 0;
    if(c == 'R') return 1;
    if(c == 'D') return 2;
    if(c == 'L') return 3;
}
bool isin(int ny, int nx, int n){
    //1-based 경계 체크
    if(ny <= 0 || nx <= 0 || ny > n || nx >  n) return 0;
    return 1;
}
int main(){
    cin >> n >> t >> r >> c >> d;
    int dir = Dir(d);
    while(t--){
        int nr = r + dy[dir];
        int nc = c + dx[dir];
        if(isin(nr, nc, n)){
            r = nr, c = nc;
        }else{
            dir = (dir + 2) % 4;
        }
    }
    cout << r << " " << c;
}


//나선 문제
#include <iostream>
using namespace std;
int const dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
int n, dir = 1, a[104][104], y, x;
bool isin(int y, int x){
    if(y < 0 || x < 0 || y >= n || x >= n) return false;
    return true;
}
int main() {
    cin >> n;
    y = x = n / 2;
    
    int num = 1;
    a[y][x] = num++;
    for(int step = 1; num <= n * n; step++){
        for(int s = 0; s < 2; s++){
            for(int i = 0; i < step; i++){
                int ny = y + dy[dir];
                int nx = x + dx[dir];
                if(isin(ny, nx) && a[ny][nx] == 0){
                    y = ny; x = nx;
                    a[y][x] = num++;
                }
            }
            dir = (dir + 3) % 4;
        }
    }
    for(int i = 0; i < n;i++){
        for(int j = 0; j < n;j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}
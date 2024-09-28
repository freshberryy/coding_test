/* 
체크판 위에서 2
r * c 크기인 직사각형의 각 칸이 w, b 색으로 표현되어 있다. 왼쪽 상단에서 출발하여 우측 하단으로 이동할 때, 아래 룰을 만족하면서 이동에 성공할 수 있는 경우의 수를 구하시오.
    1. 이동은 항상 점프를 통해서만 가능하다. 또, 점프 진행 시 항상 현재 위치에 적혀 있는 색과, 점프한 이후의 칸에 적혀 있는 색이 달라야만 한다.
    2. 점프 진행 시 현재 위치에서 적어도 한 칸 이상 오른쪽에 있는 위치이며 동시에 현재 위치에서 적어도 한 칸 이상 아래쪽에 있는 위치인 곳으로만 점프 가능하다.
    3. 정확히 시작, 도착 지점을 제외하고 점프하며 도달한 위치가 2곳 뿐이어야 한다.

5 5
W W W W W
W W W W W
W B W W W
W W W W W
W W W W B

2
*/
#include<bits/stdc++.h>
using namespace std;
int n, m, cnt;
char a[20][20];
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            for(int k = i + 1; k < n - 1; k++){
                for(int l = j + 1; l < m - 1; l++){
                    if(a[0][0] != a[i][j] && a[i][j] != a[k][l] && a[k][l] != a[n - 1][m - 1])cnt++;
                }
            }
        }
    }
    cout << cnt;
}

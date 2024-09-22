#include<bits/stdc++.h>
using namespace std;
//격자 위에서 완탐
//1*2 격자 중 좌측 모서리의 위치를 정하고, 격자를 벗어나면 안 되므로 4열까지만 순회
int n = 5;
int arr[5][5] = {{1, 0, 0, 0, 0},
                 {0, 1, 0, 0, 0},
                 {0, 1, 1, 0, 1},
                 {0, 0, 0, 1, 0},
                 {0, 0, 0, 0, 0}};

int main(){
    int mx = 0;
    for(int i = 0; i < n;i++){
        for(int j = 0; j < n - 1; j++){
            mx = max(mx, arr[i][j] + arr[i][j + 1]);
        }
    }
    cout << mx;
}

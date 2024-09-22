#include<bits/stdc++.h>
using namespace std;
//블럭이 두 개일 때
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
            for(int k = i + 1; k < n; k++){
                for(int l = 0; l < n- 1; l++){
                    mx = max(mx, arr[i][j] + arr[i][j + 1] + arr[k][l] + arr[k][l + 1]);
                }
            }
        }
    }
    cout << mx;
}

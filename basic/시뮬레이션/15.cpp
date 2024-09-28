#include <bits/stdc++.h>
using namespace std;
//2차원 배열 회전: vector 사용
vector<vector<int>> v = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
};
void rotate_right(vector<vector<int>> &v){
    int n = v.size();
    int m = v[0].size();
    vector<vector<int>> tmp(m, vector<int>(n, 0));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            tmp[i][j] = v[n - j - 1][i];
        }
    }
    v.resize(m);
    v[0].resize(n);
    v = tmp;
}
int main(){
    rotate_right(v);
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 3; j++){
            cout << v[i][j] << " ";
        }
    cout << '\n';
    }
}
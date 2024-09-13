#include<iostream>
#include<vector>
using namespace std;
int n, m, x1, y1, x2, y2, a[1030][1030], psum[1030][1030];
int main(){
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            psum[i][j] = psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1] + a[i][j];
        }
    }
    for(int i = 0; i < m; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        int ret = psum[x2][y2] - psum[x2][y1 - 1] - psum[x1 - 1][y2] + psum[x1 - 1][y1 - 1];
        cout << ret << "\n";
    }
}
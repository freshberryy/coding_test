#include<iostream>
using namespace std;
int n, m, x1, y1, x2, y2, d[1030][1030], a[1030][1030];
int main(){
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            d[i][j] = d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1] + a[i][j];
        }
    }
    for(int i = 0; i < m; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        int ret = d[x2][y2] - d[x1 - 1][y2] - d[x2][y1 - 1] + d[x1 - 1][y1 - 1];
        cout << ret << '\n';
    }
}
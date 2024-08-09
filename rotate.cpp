#include <bits/stdc++.h>
using namespace std;
int n, m;
void rotate_90(vector<vector<int>> &key){
    n = key.size(); //열 수
    m = key[0].size(); //행 수
    //벡터 초기화: vector<int> v(개수, 초기값);
    vector<vector<int>> temp(m, vector<int>(n, 0));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            temp[i][j] = key[n - j - 1][i];
        }
    }
    key.resize(m);
    key[0].resize(n);
    key = temp;
}
int main()
{
    vector<vector<int>> a = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
    };

    rotate_90(a);
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n, a[3], visited[64][64][64];
int arr[6][3] = {
    {1, 3, 9},
    {1, 9, 3},
    {3, 1, 9},
    {3, 9, 1},
    {9, 3, 1},
    {9, 1, 3}
};
struct A{
    int a, b, c;
};
int go(int a, int b, int c){
    queue<A> q;
    visited[a][b][c] = 1;
    q.push({a, b, c});
    while(q.size()){
        int a = q.front().a;
        int b = q.front().b;
        int c = q.front().c;
        q.pop();
        if(visited[0][0][0]) break;
        for(int i = 0; i < 6; i++){
            int na = max(0, a - arr[i][0]);
            int nb = max(0, b - arr[i][1]);
            int nc = max(0, c - arr[i][2]);
            if(visited[na][nb][nc]) continue;
            visited[na][nb][nc] = visited[a][b][c] + 1;
            q.push({na, nb, nc});
        }
    }
    return visited[0][0][0] - 1;
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    cout << go(a[0], a[1], a[2]);
}
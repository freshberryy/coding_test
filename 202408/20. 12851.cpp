#include <bits/stdc++.h>
using namespace std; //1
int const E = 200000;
int n, m, visited[E + 4];
long long cnt[E + 4];
int main(){
    cin >> n >> m;
    if(n == m){
        cout << 0 << "\n" << 1;
        return 0;
    }
    visited[n] = 1;
    cnt[n] = 1;
    queue<int> q;
    q.push(n);
    while(q.size()){
        int now = q.front();
        q.pop();
        for(int next : {now-1, now+1, now*2}){
            if(0 <= next && next <= E){
                if(!visited[next]){
                    visited[next] = visited[now] + 1;
                    cnt[next] += cnt[now];
                    q.push(next);
                }else if(visited[next] == visited[now] + 1){
                    cnt[next] += cnt[now];
                }
            }
        }
    }
    cout << visited[m] - 1 << "\n" << cnt[m];
    
}
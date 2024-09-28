#include <bits/stdc++.h>
using namespace std;
int sender[] = {0, 0, 1, 1, 2, 2};
int receiver[] = {1, 2, 0, 2, 0, 1};
bool visited[204][204], ret[204];
int now[3];

void bfs(){
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;
    ret[now[2]] = true;
    while(q.size()){
        int A = q.front().first;
        int B = q.front().second;
        q.pop();
        int C = now[2] - A - B;
        for(int k = 0; k < 6; k++){
            int next[] = {A, B, C};
            next[receiver[k]] += next[sender[k]];
            next[sender[k]] = 0;
            if(next[receiver[k]] > now[receiver[k]]){
                next[sender[k]] = next[receiver[k]] - now[receiver[k]];
                next[receiver[k]] = now[receiver[k]];
            }
            if(!visited[next[0]][next[1]]){
                visited[next[0]][next[1]] = true;
                q.push({next[0], next[1]});
                if(next[0] == 0) ret[next[2]] = true;
            }
        }
    }
}

int main(){
    cin >> now[0] >> now[1] >> now[2];
    bfs();
    for(int i = 0; i < 204; i++){
        if(ret[i]) cout << i << " ";
    }
}

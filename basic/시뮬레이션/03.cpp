#include<bits/stdc++.h>
using namespace std;
//[x1, x2]에 대해
//'구간'이 겹치는지 판단 -> x1부터 x2 - 1까지 표기
//'지점'이 겹치는지 판단 -> x1부터 x2까지 표기
#define OFFSET 100
int n, x1[104], x2[104], visited[204];
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x1[i] >> x2[i];
        x1[i] += OFFSET;
        x2[i] += OFFSET;
    }
    for(int i = 0; i < n;i++){
        for(int j = x1[i]; j < x2[i]; j++){
            visited[j]++;
        }
    }
    int mx = 0;
    for(int i = 0; i < 204; i++){
        mx = max(mx, visited[i]);
    }
    cout << mx;
}
/*
3
1 5 
4 6
2 4
*/
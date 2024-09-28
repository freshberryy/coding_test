/*
모이자
n개의 집이 x = 1에서 x = n까지 순서대로 놓여 있고, 각각 Ai명의 사람이 살고 있다. 이들은 n개의 집 중 한 곳에 모이려고 한다. 적절한 집을 선택하여 모든 사람들의 이동거리의 합이 최소가 되도록 하여라.*/
#include <bits/stdc++.h>
using namespace std;
int n, a[104], ret = 1e9;
int main(){
    cin >> n;
    for(int i = 0; i < n;i++){
        cin >> a[i];
    }
    //i번째 집으로 모였을 때
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = 0;j < n; j++){
            sum += abs(j - i) * a[j];
        }
        ret = min(ret, sum);
    }
    cout << ret;
}
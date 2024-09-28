/*
좌우로 움직이는 로봇
1차원 직선 안에서 1초에 한 칸씩 좌우로만 왔다 갔다 하는 로봇 a와 b가 있다. a가 움직이는 횟수 n과 b가 움직이는 횟수 m이 주어지고 각각 로봇들이 어느 방향으로 얼만큼 움직였는지가 주어졌을 때, a와 b가 바로 직전에는 다른 위치에 있다가 그 다음 번에 같은 위치에 오게 되는 경우가 총 몇 번인지를 구하는 프로그램을 작성하시오. 단, a, b는 처음에 같은 지점에서 움직이며 이는 횟수에 포함하지 않는다. 또한 각 로봇이 움직임을 종료한 이후에는 같은 위치에 계속 머물러 있으며 이때 역시 다른 로봇이 움직임에 따라 두 로봇이 같은 위치에 오게 될 수 있다. 다만, 모든 로봇이 움직인 이후의 상황은 생각하지 않는다.
첫 번째 줄에 각 로봇이 움직인 횟수 n, m이 주어진다. 다음 n번의 줄에는 a가 움직인 정보가 t, d 형태로 주어진다. t초 방향만큰 d로 이동함을 의미한다. 다음 m개의 줄에도 마찬가지다.

1 <= n, m <= 50000

4 5
3 L
5 R
1 L
2 R
4 R
1 L
3 L
4 R
2 L

3

a, b의 위치를 동시에 움직이며 직접 시뮬레이션을 하는 것은 쉽지 않다. a, b 개별적으로 시뮬레이션을 진행하되. 각각의 로봇이 매 초마다 어느 위치에 있었는지를 기록한다. 그 후 순회를 하며 그 중 시간과 위치가 동시에 일치하며, 바로 전 시간에는 두 로봇의 위치가 달랐던 시점을 찾는다.*/
#include <bits/stdc++.h>
using namespace std;
int const ee = 1000004;
int n, m, posa[ee], posb[ee], cnt, mx;
int main(){
    cin >> n >> m;
    int ta = 1;
    for(int i = 0; i < n;i++){
        char d; int t;
        cin >> t >> d;
        while(t--){
            if(d == 'R'){
                posa[ta] = posa[ta - 1] + 1;
            }else posa[ta] = posa[ta - 1] - 1;
            ta++;
        }
    }
    int tb = 1;
    for(int i = 0; i < m;i++){
        int t; char d;
        cin >> t >> d;
        while(t--){
            if(d == 'R') posb[tb] = posb[tb - 1] + 1;
            else posb[tb] = posb[tb - 1] - 1;
            tb++;
        }
    }
    if(ta < tb){
        for(int i = ta; i < tb; i++){
            posa[i] = posa[i - 1];
        }
    }else if(ta > tb){
        for(int i = tb; i < ta; i++){
            posb[i] = posb[i - 1];
        }
    }
    if(ta < tb)mx = tb;
    else mx = ta;
    for(int i = 1; i < mx; i++){
        if(posa[i] == posb[i] && posb[i - 1] != posa[i - 1])cnt++;
    }
    cout << cnt;
}


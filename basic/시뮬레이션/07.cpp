/*
선두를 지켜라
a와 b가 동일한 시작점에서 같은 방향으로 출발한다. 도중에 방향을 바꾸는 경우는 없고, a, b는 각각 n번, m번에 걸쳐 주어지는 특정 속도로 특정 시간만큼 이동한다. 선두가 몇 번이 바뀌는지 찾아 출력하시오.
첫 번째 줄에 n과 m이 주어지며, n개의 줄에 걸쳐 a의 속도와 시간인 v, t가 주어진다. 그 다음 m개의 줄에 걸쳐 b의 속도와 시간인 v, t가 주어진다.

4 3
1 2
4 1
1 1
2 10
2 3
1 2
3 9

2
*/
/*a, b 개별적으로 시뮬레이션을 진행하되, 각각의 사람이 매 초마다 어느 위치에 있었는지를 기록하는 식으로 해결한다. 각 사람의 매 초마다의 위치를 기록한 뒤, 순회를 하며 그 중 우선순위가 바뀌는 시점의 개수를 세면 된다.*/
#include <bits/stdc++.h>
using namespace std;
int const ee = 1000004;
int n, m, posa[ee], posb[ee];
int main(){
    cin >> n >> m;
    int ta = 1;
    for(int i = 0; i < n;i++){
        int v, t;
        cin >> v >> t;
        while(t--){
            posa[ta] = posa[ta - 1] + v;
            ta++;
        }
    }
    int tb = 1;
    for(int i = 0; i < m; i++){
        int v, t;
        cin >> v >> t;
        while(t--){
            posb[tb] = posb[tb - 1] + v;
            tb++;
        }
    }
    int leader = 0, ret = 0;
    for(int i = 1; i < ta; i++){
        if(posa[i] > posb[i]){
            if(leader == 2) ret++;
            leader = 1;
        }else if(posa[i] < posb[i]){
            if(leader == 1) ret++;
            leader = 2;
        }
    }
    cout << ret;
}


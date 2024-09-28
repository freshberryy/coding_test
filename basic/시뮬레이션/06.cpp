/*
만나는 그 순간
a와 b가 동일한 시작점에서 출발한다. 1초에 1m씩 움직이며, a, b 는 각각 n번, m번에 걸쳐 주어지는 방향으로 특정 시간만큼 이동한다. a, b가 움직임을 시작한 후에 최초로 만나게 되는 시간은 몇 초 후인가?

1 <= n, m <= 1000
1 <= t <= 1000

3 4
R 9
L 3
R 5
L 2
R 2
L 1
R 12

12
*/
#include <bits/stdc++.h>
using namespace std;
int const ee = 1000000;
int n, m, posa[ee + 4] , posb[ee + 4];
int main(){
    cin >> n >> m;
    int time_a = 1;
    for(int i = 0; i < n; i++){
        char d; int t;
        cin >> d >> t;
        while(t--){
            if(d == 'R'){
                posa[time_a] = posa[time_a - 1] + 1;
            }else{
                posa[time_a] = posa[time_a - 1] - 1;
            }
            time_a++;
        }
    }
    int time_b = 1;
    for(int i = 0; i < m; i++){
        char d; int t;
        cin >> d >> t;
        while(t--){
            if(d == 'R'){
                posb[time_b] = posb[time_b - 1] + 1;
            }else{
                posb[time_b] = posb[time_b - 1] - 1;
            }
            time_b++;
        }
    }
    int ret = -1;
    for(int i = 1; i < time_a; i++){
        if(posa[i] == posb[i]){
            ret = i; break;
        }
    }
    cout << ret;
}
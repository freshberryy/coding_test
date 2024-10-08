/*
왔다 갔던 구역 2
위치 0에서 시작하여 n번의 명령에 걸쳐 움직인 뒤 2번 이상 지나간 영역의 크기를 출력하시오.


1차원 배열을 새로 만들어, 주어진 구간에 대해 직접 1을 증가시키는 시뮬레이션을 진행한다. 단, 겹치는 구간을 찾는 문제이므로 배열 x1[]과 x2[]에 대해 x1[]부터 x2[] - 1까지 표기한다. 또, 음수 좌표를 갖기 때문에 주어지는 좌표에 대해 모두 오프셋을 더한 후 진행한다. 

구간이 몇 번 겹치는지 배열을 이용해 표현하기 위해서는, 각 이동마다 시작점과 도착점을 각각 배열 x1[]과 x2[]에 표시를 해 줘야 한다. 그 후, 원소 i에 대해 x1[i]부터 x2[i]까지의 값까지 checked[]에 표시한다. 

예를 들어 [0, 2], [2, -4]에 구간을 표기해줘야 한다고 생각하자. 먼저 0부터 2까지 이동하며, 배열 x1[]에 0을, 배열 x2[]에 2를 넣어주고, 2부터 -4까지 이동하며, x1[]에 -4를, x2[]에 2를 넣어준다. 그 후 checked[]에 배열 x1[]과 x2[] 사이의 구간에 표기를 해 준다. 

즉 양의 방향으로 이동할 때는 x1[]에 출발점, x2[]에 도착점을 넣는다. 음의 방향으로 이동할 때는 x2[]에 도착점, x2[]에 출발점을 넣는다. 

만약 [2, -4]와 같이 좌표가 음수일 구간이 주어진 경우라면 주어진 좌표에 대해 전부 특정 오프셋을 더해 모든 좌표를 양수로 만들어 진행한다. 주어지는 x값의 최소가 -1000이라면 오프셋을 1000으로 잡아 진행하면 된다. 

이 모든 과정을 진행한 후에는 원래 [-1000, 1000]구간에서 가장 많이 겹친 값을 구해야 하지만, 오프셋이 전부 더해진 후에 시뮬레이션을 진행하므로 [0, 2000] 내에서 최댓값을 구하면 된다.*/

#include <bits/stdc++.h>
using namespace std;
int const offset = 1000;
int n, x1[104], x2[104], checked[2004], cur;
int main(){
    cin >> n;
    for(int i = 0; i < n;i++){
        int distance;
        char direction;
        cin >> distance >> direction;
        if(direction == 'R'){
            x1[i] = cur;
            x2[i] = cur + distance;
            cur += distance;
        }else{
            x2[i] = cur;
            x1[i] = cur - distance;
            cur -= distance;
        }
        x1[i] += offset; x2[i] += offset;
    }
    for(int i = 0; i < n;i++){
        for(int j = x1[i]; j < x2[i]; j++){
            checked[j]++;
        }
    }
    int cnt = 0;
    for(int i = 0; i < 2004; i++){
        if(checked[i] >= 2) cnt++;
    }
    cout << cnt;
}
/*6
2 R
6 L
1 R
8 L
1 R
2 R

6
*/

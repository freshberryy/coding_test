/*
악수와 전염병의 상관관계 2
n명의 사람이 있으며, T번에 걸쳐 t초에 x사람이 y사람과 악수를 나눈 정황이 주어진다. 1명의 사람이 처음에 이 전염병을 옮기기 시작한 것이 확실해졌고, 사람이 이 병에 감염된 이후에는 정확히 k번의 악수동안만 전염병을 옮기게 되고, 그 이후부터는 전염병에 걸려있지만 새로 옮기지는 않게 된다. 사람들의 악수에 대한 정보와 처음 전염병에 걸린 사람 정보 p가 주어졌을 때, 모든 악수를 진행한 이후에 최종적으로 누가 전염병에 걸리게 되었는지를 알아내시오.

정수 n, k, p, T가 주어진다. 
T개의 줄에 걸쳐 t, x, y가 주어진다. 이는 t초에 x사람이 y사람과 악수했음을 의미한다.
2 <= n <= 100
1 <= k <= 250
1 <= p <= n
1 <= T <= 250
t <= t <= 250

n명의 사람에 대한 최종 감염 여부를 순서대로 출력한다. 0은 음성을, 1은 양성을 의미한다.

4 2 2 3
7 1 2 
5 2 3
6 2 4

0111

예제 설명: 4명의 사람 중에 한 사람당 최대 2번 이내의 악수에 대해서만 전염을 시킬 수 있고, 처음 2번 사람만 감염된 상황이다. 
시간 순서대로 보면 먼저 5초 때, 2번과 3번이 악수를 하게 되므로 3번은 감염이 된다. 6초에는 4번이 감염된다. 7초에 1번과 2번이 악수를 하지만 최대 두 번의 악수까지만 전염을 시킬 수 있으므로 1번은 전염되지 않는다. 따라서 최종적으로 감염이 된 사람은 2, 3, 4번이다.

해결: 각 사람이 악수한 시간과 악수한 두 사람의 번호를 shake 구조체 배열에 저장한 뒤, 배열의 시간을 오름차순으로 정렬한다. 
두 사람이 악수를 하였을 때, 상대방을 감염시킬 수 있는 횟수가 제한되었으므로, 악수 횟수를 저장하는 배열을 생성하여 악수 횟수가 k번보다 크거나 같다면 상대방을 감염시킬 수 없도록 한다. k 미만이라면 상대방을 감염시킨다.*/

#include <bits/stdc++.h>
using namespace std;
int n, k, p, T, shake_num[104];
bool infected[104];
struct Shake{
    int time, p1, p2;
    Shake(int time, int p1, int p2){
        this->time = time;
        this->p1 = p1;
        this->p2 = p2;
    }
    Shake(){}
};
bool cmp(Shake &a, Shake &b){
    return a.time < b.time;
}
int main(){
    cin >> n >> k >> p >> T;
    infected[p] = 1;
    Shake shakes[255];
    for(int i = 0; i < T; i++){
        int t, per1, per2;
        cin >> t >> per1 >> per2;
        shakes[i] = Shake(t, per1, per2);
    }
    sort(shakes, shakes + T, cmp);
    for(int i = 0; i < T; i++){
        int t1 = shakes[i].p1;
        int t2 = shakes[i].p2;
        if(infected[t1])shake_num[t1]++;
        if(infected[t2])shake_num[t2]++;
        if(shake_num[t1] <= k && infected[t1])infected[t2] = 1;
        if(shake_num[t2] <= k && infected[t2])infected[t1] = 1;
    }
    for(int i = 1; i <= n;i++){
        if(infected[i])cout << 1;
        else cout << 0;
    }
}


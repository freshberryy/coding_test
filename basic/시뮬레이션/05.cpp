/*
흰검 칠하기
일직선으로 무한히 나열된 타일이 있다. 아무 타일에서 시작하여 n번의 명령에 걸쳐 움직인다. 명령은 x L, x R 형태로만 주어지며, x L의 경우 왼쪽으로 이동하면서 현재 위치 타일을 포함 총 x칸의 타일을 흰색으로 연속하게 칠하고, x R의 경우 오른쪽으로 이동하면서 현재 위치 타일을 포함 총 x칸의 타일을 검은색으로 연속하게 칠한다. 각 명령 이후에는 마지막으로 칠한 타일 위치에 서 있는다고 가정한다. 타일의 색은 덧칠해지면 마지막으로 칠해진 색으로 바뀌는데, 만약 타일 하나가 순서 상관없이 흰색과 검은색으로 각각 두 번 이상 칠해지면 회색으로 바뀌고 더 이상 바뀌지 않는다. 모든 명령을 실행한 뒤의 흰색, 검은색, 회색의 타일 수를 각각 출력하여라.

입력 형식: 첫 번째 줄에는 n이, 그 다음부터는 n개의 줄에 걸쳐 명령이 주어진다.
1 <= n <= 1000
1 <= x <= 100
*/
#include <bits/stdc++.h>
using namespace std;
// 색칠 배열, 검은색 수 배열, 흰색 수 배열
int const offset = 100000;
int const INF = 200004;
int n, color[INF], black[INF], white[INF], b, w, grey, x;
char dir;
int main(){
    cin >> n;
    int cur = offset;
    for(int i = 0; i < n; i++){
        cin >> x >> dir;
        if(dir == 'R'){
            while(x--){
                color[cur] = 1;
                black[cur]++;
                if(x) cur++;
            }
        }else{
            while(x--){
                color[cur] = 2;
                white[cur]++;
                if(x) cur--;
            }
        }
    }
    for(int i = 0; i < INF; i++){
        if(black[i] >= 2 && white[i] >= 2)grey++;
        else if(color[i] == 1) b++;
        else if(color[i] == 2) w++;
    }
    cout << w << " " << b << " " << grey;
}
/*
4
4 R
5 L
7 R
4 L
*/
//2 3 2

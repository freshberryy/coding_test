#include <bits/stdc++.h>
using namespace std;
//1차원 배열 회전
//rotate 함수: 기본적으로 반시계로 회전
//첫 번째 인자: 전을 시작할 이터레이터
//두 번째 인자: 회전 후 첫 번째가 될 이터레이터
//세 번째 인자: 회전의 끝을 나타내는 이터레이터
vector<int> v = {1, 2, 3, 4, 5, 6};

//반시계 방향으로 한 칸씩 이동
void rot1(vector<int> v){
    rotate(v.begin(), v.begin() + 1, v.end());
    for(int i : v) cout << i << " ";
}

//반시계 방향으로 두 칸씩 이동
void rot2(vector<int> v){
    rotate(v.begin(), v.begin() + 2, v.end());
    for(int i : v) cout << i << " ";
}

//시계방향으로 한 칸씩 이동
void rot3(vector<int> v){
    rotate(v.rbegin(), v.rbegin() + 1, v.rend());
    for(int i : v) cout << i << " ";
}

int main(){
    rot1(v);
    cout << endl;
    rot2(v);
    cout << endl;
    rot3(v);
}
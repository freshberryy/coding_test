#include<bits/stdc++.h>
using namespace std;
int n, x, ret = 1e9;
vector<int> v;
//배열 맨 왼쪽 원소를 반시계로 회전
void rot(vector<int> &a){
    int f = a[0]; //첫 번째 값 저장
    for(int i = 1; i < a.size(); i++){ //원소를 왼쪽으로 이동
        a[i - 1] = a[i];
    }
    a[a.size() - 1] = f; //맨 뒤에 삽입
}
int main(){
    cin >> n;
    for(int i = 0; i < n;i++){
        cin >> x;
        v.push_back(x);
    }
    for(int i = 0; i < n;i++){
        int sum = 0;
        rot(v);
        for(int j = 0; j < n;j++){
            sum += j * v[j];
        }
        ret = min(ret, sum);
    }
    cout << ret;
}

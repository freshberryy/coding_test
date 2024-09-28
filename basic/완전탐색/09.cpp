/*
아름다운 수열 2
n개의 숫자로 이루어진 수열 a와 m개의 숫자로 이루어진 수열 b가 주어진다. 수열 b의 각 원소들의 순서를 바꿔 나오는 수열을 아름다운 수열이라고 한다. 수열 a에서 길이가 m인 연속 부분수열들 중 아름다운 수열의 수를 세는 프로그램을 작성하라.

8 3
2 4 6 7 5 7 6 4
4 6 7

2

풀이: a에서 구간의 원소와 b의 원소를 오름차순으로 정렬하여 비교했을 때, 같다면 문제의 조건에 부합하는 것이고 같지 않다면 문제의 조건을 만족하지 않는 것이다.*/
#include <bits/stdc++.h>
using namespace std;
int n, m, a[104], b[104], cnt, tmp[104];
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    sort(b, b + m);
    for(int i = 0; i <= n - m; i++){
        for(int j = 0; j < m; j++){
            tmp[j] = a[i + j]; //부분배열 추출
        }
        sort(tmp, tmp + m);
        bool same = true;;
        for(int j = 0; j < m; j++){
            if(tmp[j] != b[j]){
                same = false; break;
            }
        }
        if(same)cnt++;
    }
    cout << cnt;
}
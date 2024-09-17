#include<bits/stdc++.h>
using namespace std;
//insertion sort
int n, a[1004], s[1004], ret;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 1; i < n; i++){ //i - 1까지는 정렬됨
        int insert_point = i;
        int insert_value = a[i];
        //i 이전의 정렬된 부분에서 삽입할 위치 찾기
        for(int j = i - 1; j >= 0; j--){
            //현재 확인 중인 a[j]가, 삽입할 값보다 작으면  j + 1이 삽입할 위치가 됨
            if(a[j] < a[i]){
                insert_point = j + 1;
                break;
            }
            //마지막까지 검사했을 때 j == 0이면 삽입 위치는 0
            if(j == 0) insert_point = 0;
        }
        //삽입 위치의 오른쪽 요소들을 i까지 오른쪽으로 이동
        for(int j = i; j > insert_point; j--){
            a[j] = a[j - 1];
        }
        a[insert_point] = insert_value;
    }
    s[0] = a[0];
    for(int i = 1; i < n; i++){
        s[i] = s[i - 1] + a[i];
    }
    for(int i = 0; i < n; i++){
        ret += s[i];
    }
    cout << ret;
}
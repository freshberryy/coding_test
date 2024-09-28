#include<bits/stdc++.h>
using namespace std;
//최장 연속 부분 수열
int n = 7, ret, cnt;
int arr[] = {2, 2, 7, 7, 7, 7, 5, 7, 7};
int main(){
    for(int i = 0; i < n;i++){
        if(i >= 1 && arr[i] == arr[i + 1]) cnt++;
        else cnt = 1;
        ret = max(ret, cnt);
    }
    cout << ret;
}

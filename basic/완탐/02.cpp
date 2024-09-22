#include<bits/stdc++.h>
using namespace std;
//두 자리를 정하여 완탐
//서로 다른 두 개의 숫자를 두 배로 하여 인접한 숫자간의 차이의 합이 최대가 되게 하기
int n = 4;
int arr[] = {1, 5, 2, 6};
int main(){
    int mx = 0;
    for(int i = 0; i < n;i++){
        for(int j = i + 1; j < n;j++){
            arr[i] *= 2; arr[j] *= 2;
            int diff = 0;
            for(int k = 0; k < n - 1;k++){
                diff += abs(arr[k + 1] - arr[k]);
            }
            mx = max(mx, diff);
            arr[i] /= 2; arr[j] /= 2;
        }
    }
    cout << mx;
}
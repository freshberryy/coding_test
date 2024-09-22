#include<bits/stdc++.h>
using namespace std;
//한 자리를 정하여 완탐
//하나의 숫자만 두 배로 하여 인접한 숫자간의 차이의 합이 최대가 되게 하기
int n = 5;
int arr[] = {1, 5, 2, 6, 8};
int main(){
    int max_sum = 0;
    for(int i = 0; i < n;i++){
        arr[i] *= 2;
        int sum_diff = 0;
        for(int j = 0; j < n - 1; j++){
            sum_diff += abs(arr[j + 1] - arr[j]);
        }
        max_sum = max(max_sum, sum_diff);
        arr[i] /= 2;
    }
    cout << max_sum;
}

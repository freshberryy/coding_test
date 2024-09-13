#include<bits/stdc++.h>
using namespace std;
int n, cnt = 1, sum = 1, st = 1, ed = 1;
int main(){
    cin >> n;
    while(ed != n){
        if(sum > n){
            sum -= st;
            st++;
        }else if(sum < n){
            ed++;
            sum += ed;
        }else if(sum == n){
            ed++;
            sum += ed;
            cnt++;
        }
    }
    cout << cnt;
}
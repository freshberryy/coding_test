#include<bits/stdc++.h>
using namespace std;
//merge sort
int n;
long long ret;
vector<int> a, tmp;
void mergesort(int s, int e){
    if(e - s < 1)return;
    int m = s + (e - s) / 2;
    mergesort(s, m); mergesort(m + 1, e);
    for(int i = s; i <= e; i++){
        tmp[i] = a[i];
    }
    int k = s, idx1 = s, idx2 = m + 1;
    while(idx1 <= m && idx2 <= e){
        if(tmp[idx1] > tmp[idx2]){
            a[k] = tmp[idx2];
            ret += idx2 - k;
            k++;
            idx2++;
        }else{
            a[k] = tmp[idx1];
            k++;
            idx1++;
        }
    }
    while(idx1 <= m){
        a[k] = tmp[idx1];
        k++;
        idx1++;
    }
    while(idx2 <= e){
        a[k] = tmp[idx2];
        k++;
        idx2++;
    }
}
int main(){
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(0);
    cin >> n;
    a = vector<int>(n + 1);
    tmp = vector<int>(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    mergesort(1, n);
    cout << ret;
}
#include<bits/stdc++.h>
using namespace std;
int n, m, a[15004], cnt;
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    int i = 0, j = n - 1;
    while(i < j){
        if(a[i] + a[j] < m) i++;
        else if(a[i] + a[j] > m) j--;
        else{
            cnt++; i++; j--;
        }
    }
    cout << cnt;
}
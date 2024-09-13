#include<bits/stdc++.h>
using namespace std;
int n, a[2004], ret;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    for(int k = 0; k < n; k++){
        int find = a[k];
        int i = 0;
        int j = n - 1;
        while(i < j){
            if(a[i] + a[j] == find){
                if(i != k && j != k){
                    ret++; break;
                }else if(i == k) i++;
                else if(j == k) j--;
            }else if(a[i] + a[j] < find) i++;
            else j--;
        }
    }
    cout << ret;
}
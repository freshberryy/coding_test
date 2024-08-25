#include<bits/stdc++.h>
using namespace std;
int n = 9, a[9];
int main(){
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + 9);
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int sum  = 0;
            for(int k = 0; k < n; k++){
                if(k == i || k == j)continue;
                sum += a[k];
            }
            if(sum == 100){
                for(int k = 0; k < n; k++){
                    if(k == i || k == j)continue;
                    cout << a[k] << "\n";
                }
                return 0;
            }
        }
    }
}
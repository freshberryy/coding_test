#include<bits/stdc++.h>
using namespace std;
int a[2004][2004], x1[3], x2[3], y1[3], y2[3], cnt;
int main() {
    for(int i = 1; i <=2; i++){
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        x1[i] += 1000; x2[i] += 1000; y1[i] += 1000; y2[i] += 1000;
        for(int j = y1[i]; j < y2[i]; j++){
            for(int k = x1[i]; k < x2[i]; k++){
                if(a[j][k] == 1) a[j][k] = 3;
                else a[j][k] = i;
            }
        }
    }
    if((y2[2] >= y2[1] && y1[1] >= y1[2]) || (x1[2] <= x1[1] && x2[2] >= x2[1])){
        for(int i = 0; i < 2004; i++){
            for(int j = 0; j < 2004; j++){
                if(a[i][j] == 1)cnt++;
            }
        }
    }else{
        for(int i = 0; i < 2004; i++){
            for(int j = 0; j < 2004; j++){
                if(a[i][j] == 1 || a[i][j] == 3)cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}

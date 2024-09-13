#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
ll psum[1000004], cnt[1004], ret;
int main(){
    cin >> n >>m;
    for(int i = 1; i <= n; i++){
        int tmp = 0;
        cin >> tmp;
        psum[i] = psum[i - 1] + tmp;
    }
    for(int i = 1; i <= n; i++){
        int remainder = psum[i] % m;
        if(remainder == 0) ret++;
        cnt[remainder]++;
    }
    for(int i = 0; i < m; i++){
        if(cnt[i] > 1){
            ret += (cnt[i] * (cnt[i] - 1) / 2); 
        }
    }
    cout << ret << "\n";
}
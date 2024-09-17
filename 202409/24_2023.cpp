#include<bits/stdc++.h>
using namespace std;
int n;
bool check(int n){
    if(n <= 1) return 0;
    if(n == 2) return 1;
    if(n % 2 == 0) return 0;
    for(int i = 3; i * i <= n; i += 2){
        if(n % i == 0) return 0;
    }
    return 1;
}
void dfs(int number, int jarisu){
    if(jarisu == n){
        if(check(number)){
            cout << number << "\n";
        }
        return;
    }
    for(int i = 1; i < 10; i++){
        if(i % 2 == 0) continue;
        if(check(number * 10 + i)){
            dfs(number * 10 + i, jarisu + 1);
        }
    }
}
int main(){
    cin >> n;
    dfs(2, 1);
    dfs(3, 1);
    dfs(5, 1);
    dfs(7, 1);
}
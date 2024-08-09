#include <bits/stdc++.h>
using namespace std;
int n = 6, k = 3;
void print(vector<int> v){
    for(int i : v) cout << i << " ";
    cout << endl;
}

void combi(int start, vector<int> b){
    if(b.size() == k){
        print(b);
        return;
    }
    for(int i = start + 1; i < n; i++){
        b.push_back(i);
        combi(i, b);
        b.pop_back();
    }
}
int main(){
    vector<int> b;
    combi(-1, b);
    return 0;
}
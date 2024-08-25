#include<bits/stdc++.h>
using namespace std;
int n, cnt = 1, ret, res;
string s;
vector<string> v;
int check(vector<string> &v){
    for(int i = 0; i < v.size(); i++){
        for(int j = 1; j < v.size(); j++){
            if(v[i][j] == v[i][j - 1]){
                cnt += 1;
            }else{
                cnt = 1;
            }
            ret = max(ret, cnt);
        }
        cnt = 1;
        for(int j = 1; j < v.size(); j++){
            if(v[j][i] == v[j - 1][i]){
                cnt += 1;
            }else{
                cnt = 1;
            }
            ret = max(ret, cnt);
        }
        cnt = 1;
    }
    return ret;
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        v.push_back(s);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i + 1 < n){
                swap(v[i][j], v[i + 1][j]);
                int tmp = check(v);
                res = max(res, tmp);
                swap(v[i][j], v[i + 1][j]);
            }
            if(j + 1 < n){
                swap(v[i][j], v[i][j + 1]);
                int tmp = check(v);
                res = max(res, tmp);
                swap(v[i][j], v[i][j + 1]);
            }
        }
    }
    cout << res;
}
#include<bits/stdc++.h>
using namespace std;
string s, ret;
vector<vector<char>> key(5, vector<char>(15));
vector<vector<char>> t(vector<vector<char>> &v){
    int row = v.size();
    int col = v[0].size();
    vector<vector<char>> ret(col, vector<char>(row));
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            ret[j][i] = v[i][j];
        }
    }
    return ret;
}

int main(){
    for(int i = 0; i < 5; i++){
        cin >> s;
        for(int j = 0; j < s.size(); j++){
            key[i][j] = s[j];
        }
    }
    vector<vector<char>> v = t(key);
    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 5; j++){
            if(v[i][j]) ret += v[i][j];
        }
    }
    cout << ret;
}
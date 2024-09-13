#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> v;
    v.assign(arr1.size(), vector<int>(arr2[0].size(), 0));
    for(int i = 0; i < arr1.size(); i++){
        for(int j = 0; j < arr2[0].size(); j++){
            for(int k = 0; k < arr2.size(); k++){
                v[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    return v;
}
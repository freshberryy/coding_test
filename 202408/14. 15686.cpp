#include <bits/stdc++.h>
using namespace std; //1
int n, m, a[54][54];
vector<pair<int, int>> chicken, house;
vector<vector<int>> indexedChicken;
void combi(int start, vector<int> v){
    if(v.size() == m){
        indexedChicken.push_back(v);
        return;
    }
    for(int i = start + 1; i < chicken.size(); i++){
        v.push_back(i);
        combi(i, v);
        v.pop_back();
    }
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
            if(a[i][j] == 1)house.push_back({i, j});
            if(a[i][j] == 2)chicken.push_back({i, j});
        }
    }
    vector<int> v;
    combi(-1, v);
    int ret = 1e9;
    for(auto cVector : indexedChicken){
        int sum = 0;
        for(auto h : house){
            int mn = 1e9;
            for(auto c : cVector){
                int _dist = abs(h.first - chicken[c].first) + abs(h.second - chicken[c].second);
                mn = min(mn, _dist);
            }
            sum += mn;
        }
        ret = min(ret, sum);
    }
    cout << ret;
}


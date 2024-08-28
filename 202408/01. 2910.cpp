#include<bits/stdc++.h>
using namespace std;//1
int n, c, x;
map<int, int> mp, mp_first;
vector<pair<int, int>> v;
bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first){
        return mp_first[a.second] < mp_first[b.second];
    }
    return a.first > b.first;
}
int main(){
    cin >> n >> c;
    for(int i = 0; i < n; i++){
        cin >> x;
        mp[x]++;
        if(mp_first[x] == 0) mp_first[x] = i + 1;
    }
    for(auto it : mp){
        v.push_back({it.second, it.first});
    }
    sort(v.begin(), v.end(), cmp);
    for(auto i : v){
        for(int j = 0; j < i.first; j++){
            cout << i.second << " ";
        }
    }
}
#include<bits/stdc++.h>
using namespace std;
int n, cnt, x, y, e;
vector<pair<int, int>> v;
bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
}
int main(){
    cin >> n;
    for(int i = 0; i < n;i++){
        cin >> x; cin >> y; v.push_back({x, y});
    }
    sort(v.begin(), v.end(), cmp);
    for(int i = 0; i < n;i++){
        if(v[i].first >= e){
            e = v[i].second;
            cnt++;
        }
    }
    cout << cnt;
}

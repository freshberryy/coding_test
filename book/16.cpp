#include<bits/stdc++.h>
using namespace std;
vector<int> solution(vector<int> prog, vector<int> speeds) {
    vector<int> ret;
    int n = prog.size();
    vector<int> days_left(n);
    for(int i = 0; i < n; i++){
        days_left[i] = ceil((100.0 - prog[i]) / speeds[i]);
    }
    int cnt = 0;
    int max_day = days_left[0];
    for(int i = 0; i < n; i++){
        if(days_left[i] <= max_day) cnt++;
        else{
            ret.push_back(cnt);
            cnt = 1;
            max_day = days_left[i];
        }
    }
    ret.push_back(cnt);
    return ret;
}
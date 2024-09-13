#include<bits/stdc++.h>
using namespace std;
vector<int> ret;
bool cmp(pair<int, float> a, pair<int, float> b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second > b.second;
}
vector<int> solution(int N, vector<int> stages) {
    vector<float> challenger(N + 2, 0.0);
    vector<float> fail(N + 2, 0.0);
    for(int i = 0; i < stages.size(); i++){
        for(int j = 1; j <= stages[i]; j++){
            challenger[j]++;
        }
        fail[stages[i]]++;
    }
    vector<pair<int, float>> failRatio(N);
    for(int i = 0; i < N; i++){
        failRatio[i].first = i + 1;
        if(challenger[i + 1] == 0)failRatio[i].second = 0;
        else failRatio[i].second = fail[i + 1] / challenger[i + 1];
    }
    sort(failRatio.begin(), failRatio.end(), cmp);
    for(int i = 0; i < N; i++){
        ret.push_back(failRatio[i].first);
    }
    return ret;
}
int main(){
    vector<int> v = {2, 1, 2, 6, 2, 4, 3, 3};
    for(int i : solution(5, v)) cout << i << " ";
}
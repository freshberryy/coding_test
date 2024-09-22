#include<bits/stdc++.h>
using namespace std;
vector<int> v;
vector<pair<int, float>> fratio;
bool cmp(pair<int, float>&a, pair<int, float>&b){
	if(a.second == b.second) return a.first < b.first;
	return a.second > b.second;
}
vector<int> solution(int n, vector<int> stages) {
    vector<int> challenger(n + 2);
	for(int stage : stages){
		challenger[stage]++;
	}
	float total = stages.size();
	for(int i = 1; i <= n;i++){
		if(challenger[i] == 0){
			fratio.push_back({i, 0.0});
		}
		else{
			fratio.push_back({i, challenger[i] / total});
			total -= challenger[i];
		}
	}
	sort(fratio.begin(), fratio.end(), cmp);
	for(int i = 0; i < n;i++){
		v.push_back(fratio[i].first);
	}
	return v;
}
int main(){
    vector<int> v = {2, 1, 2, 6, 2, 4, 3, 3};
    for(int i : solution(5, v)) cout << i << " ";
}
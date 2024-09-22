#include<bits/stdc++.h>
using namespace std;
bool cmp(int a, int b){
	return a > b;
}
vector<int> solution(vector<int> list){
	sort(list.begin(), list.end(), cmp);
	list.erase(unique(list.begin(), list.end()), list.end());
	return list;
}
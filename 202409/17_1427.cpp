#include<bits/stdc++.h>
using namespace std;
//selection sort
string s;
vector<int> v;
int main(){
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        v.push_back(s[i] - '0');
    }
    for(int i = 0; i < s.size(); i++){ //i는 남은 정렬 부분(index++)
        int mx = i;
        for(int j = i + 1; j < s.size(); j++){
            if(v[j] > v[mx]) mx = j; //내림차순이므로 최대값 찾기
        }
        if(v[i] < v[mx]) swap(v[i], v[mx]); //남은 정렬 부분의 가장 왼쪽과 최대값 교환
    }
    for(int i : v) cout << i;
}
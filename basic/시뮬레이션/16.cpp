#include <bits/stdc++.h>
using namespace std;
//조합-재귀
//서로 다른 5개의 구슬이 들어 있는 주머니에서 3개의 구슬 뽑기
//5C3
int n = 5, r = 3;
int arr[] = {1, 2, 3, 4, 5};
vector<int> v;
void print(vector<int> v){
    for(auto i : v){
        cout << i << " ";
    }
    cout << endl;
}

void combi(int start, vector<int> v){
    //3개의 구슬이 뽑아지면
    if(v.size() == 3){
        print(v);
        return;
    }
    //5개 중
    for(int i = start + 1; i < 5; i++){
        v.push_back(arr[i]);
        combi(i, v);
        v.pop_back();
    }
}
int main(){
    combi(-1, v);
}
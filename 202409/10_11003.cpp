#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> node;
int n, l, now;
deque<node> dq;
int main(){
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(0);
    cin >> n >> l;
    for(int i = 0; i < n; i++){
        cin >> now;
        while(dq.size() && dq.back().first > now){
            dq.pop_back();
        }
        dq.push_back(node(now, i));
        if(dq.front().second <= i - l){
            dq.pop_front();
        }
        cout << dq.front().first << " ";
    }
}
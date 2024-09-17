#include<bits/stdc++.h>
using namespace std;
int n, x;
struct cmp{
    bool operator()(int o1, int o2){
        int a = abs(o1);
        int b = abs(o2);
        if(a == b){
            return o1 > o2;
        }
        return a > b;
    }
};
priority_queue<int, vector<int>, cmp> pq;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        if(x == 0){
            if(pq.empty()) cout << "0\n";
            else{
                cout << pq.top() << '\n';
                pq.pop();
            }
        }else{
            pq.push(x);
        }
    }
}
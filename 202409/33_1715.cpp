#include<bits/stdc++.h>
using namespace std;
int n, card, sum, data1, data2;
priority_queue<int, vector<int>, greater<int>> pq;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> card;
        pq.push(card);
    }
    while(pq.size() != 1){
        data1 = pq.top();
        pq.pop();
        data2 = pq.top();
        pq.pop();
        sum += data1 + data2;
        pq.push(data1 + data2);
    }
    cout << sum;
}
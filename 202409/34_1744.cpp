#include<bits/stdc++.h>
using namespace std;
int n, one, zero, x, sum;
priority_queue<int> pluspq;
priority_queue<int, vector<int>, greater<int>> minuspq;
int main(){
    cin >> n;
    for(int i = 0; i < n;i++){
        cin >> x;
        if(x > 1) pluspq.push(x);
        else if(x == 1) one++;
        else if(x == 0) zero++;
        else minuspq.push(x);
    }
    while(pluspq.size() > 1){
        int f = pluspq.top();
        pluspq.pop();
        int s = pluspq.top();
        pluspq.pop();
        sum += f * s;
    }
    if(pluspq.size()){
        sum += pluspq.top();
        pluspq.pop();
    }
    while(minuspq.size() > 1){
        int f = minuspq.top();
        minuspq.pop();
        int s = minuspq.top();
        minuspq.pop();
        sum += f * s;
    }
    if(minuspq.size()){
        if(zero == 0){
            sum += minuspq.top();
            minuspq.pop();
        }
    }
    sum += one;
    cout << sum;
}

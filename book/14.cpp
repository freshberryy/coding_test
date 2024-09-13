#include<bits/stdc++.h>
using namespace std;
string solution(int n, int k, vector<string> cmd) {
    string ret(n, 'O');
    vector<int> prev(n), next(n);
    stack<int> deleted;
    for(int i = 0; i < n; i++){
        prev[i] = i - 1;
        next[i] = i + 1;
    }
    next[n - 1] = -1;
    int curr = k;
    for(string c : cmd){
        if(c[0] == 'U'){
            int x = stoi(c.substr(2));
            while(x--)curr = prev[curr];
        }else if(c[0] == 'D'){
            int x = stoi(c.substr(2));
            while(x--)curr = next[curr];
        }else if(c[0] == 'C'){
            deleted.push(curr);
            ret[curr] = 'X';
            if(prev[curr] != -1) next[prev[curr]] = next[curr];
            if(next[curr] != -1) prev[next[curr]] = prev[curr];
            curr = (next[curr] == -1) ? prev[curr] : next[curr];
        }else{
            int restore = deleted.top();
            deleted.pop();
            ret[restore] = 'O';
            if(prev[restore] != -1) next[prev[restore]] = restore;
            if(next[restore] != -1) prev[next[restore]] = restore;
        }
    }
    return ret;
}
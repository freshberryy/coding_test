#include<bits/stdc++.h>
using namespace std;
string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    queue<string> c1, c2, g;
    for(string s : cards1) c1.push(s);
    for(string s : cards2) c2.push(s);
    for(string s : goal) g.push(s);
    while(g.size()){
        if(c1.size() && c1.front() == g.front()){
            c1.pop(); g.pop();
        }
        else if(c2.size() && c2.front() == g.front()){
            c2.pop(); g.pop();
        }else break;
    }
    return g.empty() ? "Yes" : "No";
}
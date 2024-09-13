#include<bits/stdc++.h>
using namespace std;
vector<int> solution(vector<int> prices){
   vector<int> ret(prices.size());
   int n = prices.size();
   stack<int> s;
   for(int i = 0; i < n; i++){
      while(s.size() && prices[s.top()] > prices[i]){
         ret[s.top()] = i - s.top();
         s.pop();
      }
      s.push(i);
   }
   while(s.size()){
      ret[s.top()] = n - 1 - s.top();
      s.pop();
   }
   return ret;
}
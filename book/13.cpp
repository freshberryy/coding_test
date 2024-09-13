#include<bits/stdc++.h>
using namespace std;
int solution(vector<vector<int>> board, vector<int> moves){
   stack<int> lanes[board[0].size()];
   for(int i = board.size() - 1; i >= 0; i--){
      for(int j = 0; j < board[0].size(); j++){
         if(board[i][j]){
            lanes[j].push(board[i][j]);
         }
      }
   }
   stack<int> bucket;
   int ret = 0;
   for(int m : moves){
      m -= 1;
      if(lanes[m].size()){
         int doll = lanes[m].top();
         lanes[m].pop();
         if(bucket.size() && bucket.top() == doll){
            bucket.pop();
            ret += 2;
         }else{
            bucket.push(doll);
         }
      }
   }
   return ret;
}

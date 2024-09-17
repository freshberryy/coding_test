#include<bits/stdc++.h>
using namespace std;
int n, a[100004], num = 1;
vector<char> ret;
stack<int> s;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        int su = a[i];
        if(su >= num){
            while(su >= num){
                s.push(num++);
                ret.push_back('+');
            }
            s.pop();
            ret.push_back('-');
        }else{
            int n = s.top();
            s.pop();
            if(n > su){
                cout << "NO";
                return 0;
            }else{
                ret.push_back('-');
            }
        }
    }
    for(int i = 0; i < ret.size(); i++){
        cout << ret[i] << "\n";
    }
}
#include<bits/stdc++.h>
using namespace std;
//이진수->십진수 변환
int main(){
    int bi[] = {1, 1, 1, 0, 1};
    int num = 0;
    for(int i = 0; i < 5; i++){
        num = num * 2 + bi[i];
    }
    cout << num;
}

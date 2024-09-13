#include<bits/stdc++.h>
using namespace std;
int main(){
    int S = 18;
    cout << "original: " <<bitset<8>(S) << "\n";
    int idx = 0;
    S |= (1 << idx);
    cout <<bitset<8>(S);
    //cout << "setted lsb: " << (-S & S);
}
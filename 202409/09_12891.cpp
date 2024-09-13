#include<bits/stdc++.h>
using namespace std;
int base[4], my[4], check, s, p, ret;
string a;
void Add(char c){
    switch(c){
        case 'A':
            my[0]++;
            if(my[0] == base[0])check++;
            break;
        case 'C':
            my[1]++;
            if(my[1] == base[1])check++;
            break;
        case 'G':
            my[2]++;
            if(my[2] == base[2])check++;
            break;
        case 'T':
            my[3]++;
            if(my[3] == base[3])check++;
            break;
    }
}
void Remove(char c){
    switch(c){
        case 'A':
            if(my[0] == base[0]) check--;
            my[0]--;
            break;
        case 'C':
            if(my[1] == base[1]) check--;
            my[1]--;
            break;
        case 'G':
            if(my[2] == base[2]) check--;
            my[2]--;
            break;
        case 'T':
            if(my[3] == base[3]) check--;
            my[3]--;
            break;
    }
}
int main(){
    cin >> s >> p >> a;
    for(int i = 0; i < 4; i++){
        cin >> base[i];
        if(base[i] == 0) check++;
    }
    for(int i = 0; i < p; i++){
        Add(a[i]);
    }
    if(check == 4) ret++;
    for(int i = p; i < s; i++){
        int j = i - p;
        Add(a[i]);
        Remove(a[j]);
        if(check == 4) ret++;
    }
    cout << ret;
}
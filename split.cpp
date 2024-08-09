#include<bits/stdc++.h>
using namespace std;
vector<string> split(string &input, string delim){
    vector<string> ret;
    int start = 0;
    int end = input.find(delim);
    while(end != string::npos){
        ret.push_back(input.substr(start, end - start));
        start = end + delim.size();
        end = input.find(delim, start);
    }
    ret.push_back(input.substr(start));
    return ret;
}
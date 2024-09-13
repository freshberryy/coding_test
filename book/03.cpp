#include<bits/stdc++.h>
using namespace std;
vector<int> solution(vector<int> numbers){
    set<int> sum;
    for(int i = 0; i < numbers.size(); i++){
        for(int j = i + 1; j < numbers.size(); j++){
            sum.insert(numbers[i] + numbers[j]);
        }
    }
    vector<int> ret(sum.begin(), sum.end());
    return ret;
}
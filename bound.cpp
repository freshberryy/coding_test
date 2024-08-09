#include<bits/stdc++.h>
using namespace std;
//lower_bound(): 어떤 값이 처음 나오는 이터레이터 반환
//upper_bound(): 어떤 값을 초과하는 첫 번째 값의 이터레이터 반환
// 정렬된 배열에 쓸 것
int main(){
    vector<int> a {1, 2, 3, 3, 3, 4};
    cout << lower_bound(a.begin(), a.end(), 3) - a.begin() << "\n"; // 2
    cout << upper_bound(a.begin(), a.end(), 3) - a.begin() << "\n"; // 5
}
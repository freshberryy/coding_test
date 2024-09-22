#include<bits/stdc++.h>
using namespace std;
//특정 인덱스 제외 연산: 외부 루프가 제외할 인덱스
int n, x, y, sum, ret = 1e9;
vector<pair<int, int>> v;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        v.push_back({ x, y });
    }

    for (int i = 1; i < n - 1; i++) {
        sum = 0;
        int pre = 0;
        for (int j = 1; j < n; j++) {
            if (j == i)continue;
            sum += abs(v[pre].first - v[j].first) + abs(v[pre].second - v[j].second);
            pre = j;
        }
        ret = min(ret, sum);
    }

    cout << ret << endl;
    return 0;
}

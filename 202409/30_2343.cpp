#include<bits/stdc++.h>
using namespace std;
int n, m, a[100004], s, e, sum, cnt;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s = max(s, a[i]);
		e += a[i];
	}
	while (s <= e) {
		sum = 0, cnt = 0;
		int mid = s + (e - s) / 2;
		for (int i = 0; i < n; i++) {
			if (sum + a[i] > mid) {
				cnt++; sum = 0;
			}
			sum += a[i];
		}
		if (sum)cnt++;
		if (cnt > m) s = mid + 1;
		else e = mid - 1;
	}
	cout << s;
}
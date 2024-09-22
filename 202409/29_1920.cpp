#include<bits/stdc++.h>
using namespace std;
int n, m, a[100004], target, st, ed;
int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	cin >> m;
	for (int i = 0; i < m; i++) {
		bool find = false;
		cin >> target;
		st = 0, ed = n - 1;
		while (st <= ed) {
			int midi = (st + ed) / 2;
			int midv = a[midi];
			if (midv > target) {
				ed = midi - 1;
			}
			else if (midv < target) {
				st = midi + 1;
			}
			else {
				find = true;
				break;
			}
		}
		if (find) cout << 1 << "\n";
		else cout << 0 << "\n";
	}
}
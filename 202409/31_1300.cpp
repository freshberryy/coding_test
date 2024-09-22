#include <iostream>
using namespace std;
int n, k, ret, cnt;
int main() {
	cin >> n >> k;
	int s = 1, e = k;
	while (s <= e) {
		int mid = s + (e - s) / 2;
		cnt = 0;
		for (int i = 1; i <= n; i++) {
			cnt += min(mid / i, n);
		}
		if (cnt < k) s = mid + 1;
		else {
			ret = mid;
			e = mid - 1;
		}
	}
	cout << ret;
}

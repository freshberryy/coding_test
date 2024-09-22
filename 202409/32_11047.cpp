#include<bits/stdc++.h>
using namespace std;
int n, k, cnt;
int main() {
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n;i++){
		cin >> a[i];
	}
	for(int i = n - 1; i >= 0; i--){
		if(a[i] <= k){
			cnt += k / a[i];
			k %= a[i];
		}
	}
	cout << cnt;
}
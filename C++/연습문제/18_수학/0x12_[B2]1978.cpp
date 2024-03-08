#include <bits/stdc++.h>

using namespace std;

int prime[1005], n, ans = 0;

int main() {
	prime[1] = 1;
	for (int i = 2; i <= 1000; i++) {
		if (prime[i] == 1) continue;
		for (int j = 2; i * j <= 1000; j++) {
			prime[i * j] = 1;
		}
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		ans += !(prime[k]);
	}
	cout << ans;
}
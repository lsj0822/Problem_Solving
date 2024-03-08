#include <bits/stdc++.h>

using namespace std;
int n;
bool prime[1000005];
int main() {
	fill(&prime[0], &prime[1000001], true);
	for (int i = 2; i <= 1000000; i++) {
		if (!prime[i]) continue;
		for (int j = 2; i * j <= 1000000; j++) {
			prime[i * j] = false;
		}
	}
	cin >> n;
	while (n--) {
		int k, ans = 0;
		cin >> k;
		for (int i = 2; i <= k / 2; i++) {
			if (prime[i] && prime[k - i]) ans++;
		}
		cout << ans << '\n';
	}
}
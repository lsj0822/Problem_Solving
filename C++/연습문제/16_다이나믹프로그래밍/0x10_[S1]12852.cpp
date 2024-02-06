#include <bits/stdc++.h>

using namespace std;
int n, ans[1000005], track[1000005];
int main() {
	cin >> n;
	ans[2] = 1; track[2] = 1;
	for (int i = 3; i <= n; i++) {
		ans[i] = ans[i - 1] + 1;
		track[i] = i - 1;
		if (!(i % 2) && ans[i / 2] + 1 < ans[i]) {
			ans[i] = ans[i / 2] + 1;
			track[i] = i / 2;
		}
		if (!(i % 3) && ans[i / 3] + 1 < ans[i]) {
			ans[i] = ans[i / 3] + 1;
			track[i] = i / 3;
		}
	}
	cout << ans[n] << '\n' << n << " ";
	int res = n;
	while (ans[n]--) {
		cout << track[res] << " ";
		res = track[res];
	}
}
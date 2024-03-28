#include <bits/stdc++.h>

using namespace std;
int n, c, gong[200005], ans = -1;
int main() {
	cin >> n >> c;
	for (int i = 0; i < n; i++) cin >> gong[i];
	sort(&gong[0], &gong[n]);
	int st = 0, en = 1000000000, mid;
	while (st <= en) {
		mid = (st + en) / 2;
		int crit = gong[0], cnt = 1;
		for (int i = 1; i < n; i++) {
			if (gong[i] - crit >= mid) {
				crit = gong[i];
				cnt++;
			}
		}
		if (cnt >= c) {
			ans = mid;
			st = mid + 1;
		}
		else en = mid -1;
	}
	cout << ans;
}
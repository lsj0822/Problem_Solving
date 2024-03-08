#include <bits/stdc++.h>

using namespace std;

int t;
int main() {
	cin >> t;
	while (t--) {
		int m, n, x, y;
		bool ans = false;
		cin >> m >> n >> x >> y;
		for (int i = x; i < m * n; i += m) {
			if (i % n == y) {
				cout << i << '\n';
				ans = true;
				break;
			}
		}
		if (!ans) cout << -1 << '\n';
	}
}
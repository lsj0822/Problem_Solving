#include <bits/stdc++.h>

using namespace std;

int t, n, m, s, ans, tmp;

int main() {
	cin >> t;
	while (t--) {
		ans = 0; tmp = 0;
		pair<int, int> arr[40005];
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> s;
			arr[i] = { -s,1 };
		}
		for (int j = n; j < n + m; j++) {
			cin >> s;
			arr[j] = { -s,0 };
		}
		sort(&arr[0], &arr[n + m]);
		for (int i = 0; i < n + m; i++) {
			if (arr[i].second) tmp++;
			else ans += tmp;
		}
		cout << ans << '\n';
	}
}
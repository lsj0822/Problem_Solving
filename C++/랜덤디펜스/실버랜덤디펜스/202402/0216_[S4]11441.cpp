#include <bits/stdc++.h>

using namespace std;

int n, m, sum[100005], total = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		total += k;
		sum[i] = total;
	}
	cin >> m;
	while (m--) {
		int st, en;
		cin >> st >> en;
		cout << sum[en] - sum[st-1] << '\n';
	}
}
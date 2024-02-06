#include <bits/stdc++.h>

using namespace std;

int n, m, r[100005], s[100005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> r[i];
	s[0] = r[0];
	for (int i = 1; i < n; i++) s[i] = s[i-1] + r[i];
	while (m--) {
		int i, j;
		cin >> i >> j;
		cout << s[j-1] - s[i - 2] << '\n';
	}
}

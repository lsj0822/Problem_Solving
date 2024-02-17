#include <bits/stdc++.h>

using namespace std;

int n;
long long ans = 0, muscle[10005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> muscle[i];
	}
	sort(&muscle[0], &muscle[n]);
	if (n % 2) {
		ans = muscle[n - 1];
		n--;
	}
	for (int i = 0; i * 2 < n; i++) {
		ans = max(ans, muscle[i] + muscle[n-1-i]);
	}
	cout << ans;
}
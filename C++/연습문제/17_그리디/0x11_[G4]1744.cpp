#include <bits/stdc++.h>

using namespace std;
int n, pos[55], neg[55], zero = 0, pidx = 0, nidx = 0, ans = 0;

bool reversed(int a, int b) {
	return a > b;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		if (k > 0) pos[pidx++] = k;
		else if (k < 0) neg[nidx++] = k;
		else zero++;
	}
	sort(&pos[0], &pos[pidx], reversed);
	sort(&neg[0], &neg[nidx]);
	if (pidx % 2) ans += pos[pidx - 1];
	for (int i = 0; i < pidx-1; i+=2) {
		if (pos[i] > 1 && pos[i + 1] > 1) ans += pos[i] * pos[i + 1];
		else ans += pos[i] + pos[i + 1];
	}
	if (nidx % 2) {
		if (zero) nidx--;
		else ans += neg[nidx - 1];
	}
	for (int i = 0; i < nidx - 1; i += 2) {
		ans += neg[i] * neg[i + 1];
	}
	cout << ans;
}
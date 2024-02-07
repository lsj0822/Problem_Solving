#include <bits/stdc++.h>

using namespace std;

int n, task[1500005][2], res[1500005], di;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> task[i][j];
		}
	}
	for (int i = n-1; i >= 0; i--) {
		di = i + task[i][0];
		if (di <= n)res[i] = max(task[i][1] + res[di], res[i + 1]);
		else res[i] = res[i + 1];
	}
	cout << res[0];
}
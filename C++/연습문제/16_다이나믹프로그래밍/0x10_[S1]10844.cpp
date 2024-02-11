#include <bits/stdc++.h>

using namespace std;
int n, arr[105][10], MOD = 1000000000, ans = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	if (n == 1) {
		cout << 9;
		return 0;
	}
	for (int i = 1; i <= 9; i++) {
		arr[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		arr[i][0] = arr[i - 1][1];
		for (int j = 1; j < 9; j++) {
			arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j + 1]) % MOD;
		}
		arr[i][9] = arr[i - 1][8];
	}
	for (int i = 0; i < 10; i++) {
		ans = (ans + arr[n][i]) % MOD;
	}
	cout << ans;
}
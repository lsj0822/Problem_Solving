#include <bits/stdc++.h>

using namespace std;

int n, arr[505][505], ans[505][505], res = -1;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> arr[i][j];
		}
	}
	ans[0][0] = arr[0][0]; ans[1][0] = arr[0][0] + arr[1][0]; ans[1][1] = arr[0][0] + arr[1][1];
	for (int i = 2; i < n; i++) {
		ans[i][0] = ans[i - 1][0] + arr[i][0];
		for (int j = 1; j < i; j++) {
			ans[i][j] = max(ans[i - 1][j], ans[i - 1][j - 1]) + arr[i][j];
		}
		ans[i][i] = ans[i - 1][i - 1] + arr[i][i];
	}
	for (int i = 0; i < n; i++) {
		res = max(res, ans[n - 1][i]);
	}
	cout << res;
}
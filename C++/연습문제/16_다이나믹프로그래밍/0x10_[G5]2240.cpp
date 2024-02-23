#include <bits/stdc++.h>

using namespace std;
int t, w, combo = 1, recent, idx = 0, arr[1005], ans[1005][30], res = -1;
int main() {
	cin >> t >> w >> recent;
	if (recent == 2) idx++;
	for (int i = 1; i < t; i++) {
		int num;
		cin >> num;
		if (num != recent) {
			arr[idx++] = combo;
			combo = 0;
		}
		combo++;
		recent = num;
	}
	arr[idx] = combo;
	ans[0][0] = arr[0];
	for (int i = 1; i <= idx; i++) {
		if (!(i % 2)) ans[i][0] = ans[i - 1][0] + arr[i];
		else ans[i][0] = ans[i - 1][0];
		for (int j = 1; j <= i; j++) {
			if (!((i + j) % 2) && j <= w) {
				ans[i][j] = ans[i - 1][j] + arr[i];
				ans[i][j] = max(ans[i][j], ans[i-1][j-1] + arr[i]);
			}
			else {
				ans[i][j] = ans[i - 1][j];
			}
		}
	}
	for (int i = 0; i <= w; i++) {
		res = max(res, ans[idx][i]);
	}
	cout << res;
}
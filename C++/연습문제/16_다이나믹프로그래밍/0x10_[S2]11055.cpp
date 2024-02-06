#include <bits/stdc++.h>

using namespace std;
int n, arr[1005], dp[1005][2], ans = -1;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	dp[0][0] = arr[0];
	dp[0][1] = arr[0];
	for (int i = 1; i < n; i++) {
		dp[i][0] = arr[i];
		dp[i][1] = arr[i];
		for (int j = i-1; j >= 0; j--) {
			if (dp[j][1] < arr[i] && dp[i][0] < dp[j][0] + arr[i]) {
				dp[i][0] = dp[j][0] + arr[i];
				dp[i][1] = arr[i];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		ans = max(ans, dp[i][0]);
	}
	cout << ans;
}
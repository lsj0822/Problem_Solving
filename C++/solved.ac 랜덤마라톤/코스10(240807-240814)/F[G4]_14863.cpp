#include<iostream>
using namespace std;
int dp[100001][101], n, k, ans = 0;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		int wt, wm, ct, cm;
		cin >> wt >> wm >> ct >> cm;
		if (i == 1) {
			dp[wt][1] = wm;
			dp[ct][1] = max(dp[ct][1], cm);
		}
		else {
			for (int t = 0; t <= k; t++) {
				if (dp[t][i - 1] == 0) continue;
				if (t + wt <= k) dp[t + wt][i] = max(dp[t][i - 1] + wm, dp[t + wt][i]);
				if (t + ct <= k) dp[t + ct][i] = max(dp[t][i - 1] + cm, dp[t + ct][i]);
			}
		}
	}
	for (int t = 0; t <= k; t++) ans = max(ans, dp[t][n]);
	cout << ans;
}
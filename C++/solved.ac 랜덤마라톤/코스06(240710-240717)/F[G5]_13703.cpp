#include<iostream>
using namespace std;
int k, n;
long long dp[128][64], ans = 0;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> k >> n;
	if (k == 0) {
		cout << 0;
		return 0;
	}
	else if (n == 0) {
		cout << 1;
		return 0;
	}
	dp[k + 1][1] = 1;
	if(k > 1) dp[k - 1][1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= k+n; j++) {
			dp[j][i] = dp[j - 1][i - 1] + dp[j + 1][i - 1];
		}
	}
	for (int i = 1; i <= k + n; i++) ans += dp[i][n];
	cout << ans;
}
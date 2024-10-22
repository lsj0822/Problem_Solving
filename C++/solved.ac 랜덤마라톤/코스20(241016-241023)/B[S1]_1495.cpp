#include<iostream>
using namespace std;
int n, s, m, arr[55], ans = -1;
bool dp[55][1005];
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> s >> m;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	dp[0][s] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (!dp[i-1][j]) continue;
			if (j - arr[i] >= 0) dp[i][j - arr[i]] = 1;
			if (j + arr[i] <= m) dp[i][j + arr[i]] = 1;
		}
	}
	for (int i = 0; i <= m; i++) if (dp[n][i]) ans = i;
	cout << ans;
}
#include <bits/stdc++.h>

using namespace std;

int n, m, dp[1005][1005], ans = 0;
string board[1005];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> board[i];
	for (int i = 0; i < m; i++) dp[0][i] = board[0][i]-'0';
	for (int i = 0; i < n; i++) dp[i][0] = board[i][0]-'0';
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (board[i][j] == '1') dp[i][j] = min({dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]}) + 1;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) ans = max(ans, dp[i][j]);
	}
	cout << ans * ans;
}
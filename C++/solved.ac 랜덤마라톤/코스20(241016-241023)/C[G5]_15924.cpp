#include<iostream>
using namespace std;
const int SIZE = 3005, MOD = 1e9+9;
int dp[SIZE][SIZE], n, m;
char arr[SIZE][SIZE];
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			dp[i][j] = 1;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			switch (arr[i][j]) {
			case 'B':
				dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MOD;
				dp[i][j + 1] = (dp[i][j] + dp[i][j + 1]) % MOD;
				break;
			case 'E':
				dp[i][j + 1] = (dp[i][j] + dp[i][j + 1]) % MOD;
				break;
			case 'S':
				dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MOD;
				break;
			default:
				break;
			}
		}
	}
	cout << dp[n - 1][m - 1];
}
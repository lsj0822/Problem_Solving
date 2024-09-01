#include<iostream>
using namespace std;
int n, k, dp[10005][1005];
int main() {
	cin >> n >> k;
	for (int i = 1; i <= k; i++) {
		int I, T;
		cin >> I >> T;
		for (int j = 0; j <= n; j++) {
			if (j - T >= 0) dp[j][i] = max(dp[j][i - 1], dp[j - T][i - 1] + I);
			else dp[j][i] = dp[j][i - 1];
		}
	}
	cout << dp[n][k];
}
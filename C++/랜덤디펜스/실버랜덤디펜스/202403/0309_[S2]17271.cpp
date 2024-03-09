#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int n, m, dp[10005];
int main(void)
{
	cin >> n >> m;
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		if (i - m >= 0) dp[i] = (dp[i - 1] + dp[i - m]) % MOD;
		else dp[i] = dp[i - 1];
	}
	cout << dp[n];
}
#include<iostream>
#include<algorithm>
using namespace std;
int n, arr[25], prefix = 0;
bool dp[2005][2005];
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		prefix += arr[i];
	}
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = prefix; j >= 0; j--) {
			for (int k = prefix; k >= 0; k--) {
				int w = arr[i];
				if (j - w >= 0) dp[j][k] = (dp[j][k] || dp[j - w][k]);
				if (k - w >= 0) dp[j][k] = (dp[j][k] || dp[j][k - w]);
			}
		}
	}
	int ans = prefix;
	for (int i = 0; i <= prefix; i++) {
		for (int j = 0; j <= i; j++) {
			if (dp[i][j] && j >= prefix - i - j) {
				ans = min(ans, i);
			}
		}
	}
	cout << ans;
}
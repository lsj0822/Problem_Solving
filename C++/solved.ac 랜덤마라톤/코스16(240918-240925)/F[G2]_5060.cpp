#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cmath>
using namespace std;
int t, h, c, arr[205];
double dp[205][205], ans, errorls[205][205];
double lderror(int srt, int end) {
	int len = end - srt;
	double delta = (arr[end] - arr[srt]) / (double)len;
	double res = 0;
	for (int i = srt + 1; i < end; i++) {
		res += abs((arr[srt] + delta * (i - srt)) - arr[i]);
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> h >> c;
		fill(&dp[0][0], &dp[h + 1][0], 1e9);
		ans = 1e9;
		for (int i = 1; i <= h; i++) dp[i][i] = 0;
		for (int i = 1; i <= h; i++) cin >> arr[i];

		for (int i = 1; i <= h; i++) {
			for (int j = i + 1; j <= h; j++) {
				errorls[i][j] = lderror(i, j);
			}
		}

		for (int i = 2; i <= c; i++) {
			for (int j = 1; j <= h; j++) {
				for (int k = j + 1; k <= h; k++) {
					dp[i][k] = min(dp[i][k], dp[i - 1][j] + errorls[j][k]);
				}
			}
		}
		for (int i = 1; i <= c; i++) ans = min(ans, dp[i][h]);
		cout << fixed;
		cout << setprecision(4) << ans / h << '\n';
	}
}
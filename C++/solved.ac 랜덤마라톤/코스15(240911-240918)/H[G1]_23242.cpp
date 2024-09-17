#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int arr[4005], presum[4005], squaresum[4005], b, n;
double dp[4005][35];
const int INF = 1e9;
double ans = INF;

double calfreq(int srt, int end) {
	int flen = end - srt + 1;
	double powmean = (double)(squaresum[end] - squaresum[srt - 1]) / flen;
	double mean = (double)(presum[end] - presum[srt - 1]) / flen;
	return (powmean - mean * mean) * flen;
}
int main() {
	cin >> b >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		presum[i] = presum[i - 1] + arr[i];
		squaresum[i] = squaresum[i - 1] + arr[i] * arr[i];
	}
	fill(&dp[0][0], &dp[n + 1][0], INF);
	for (int i = 1; i <= n; i++) {
		dp[i][1] = calfreq(1, i);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= b; j++) {
			for (int k = 1; k < i; k++) {
				dp[i][j] = min(dp[i][j], dp[k][j - 1] + calfreq(k + 1, i));
			}
		}
	}
	for (int i = 1; i <= b; i++) ans = min(ans, dp[n][i]);
	cout << fixed;
	cout << setprecision(6) << ans;
}
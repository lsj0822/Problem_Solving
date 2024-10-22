#include<iostream>
#include<cmath>
#include<algorithm>
#define X first
#define Y second
#define ll long long
using namespace std;
int n;
pair<ll,ll> arr[5005];
ll dp[5005];
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	fill(&dp[0], &dp[n + 1], 1e18);
	for (int i = 0; i < n; i++) {
		cin >> arr[i].X >> arr[i].Y;
		arr[i].X = abs(arr[i].X);
		arr[i].Y = abs(arr[i].Y);
	}
	sort(&arr[0], &arr[n]);
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		ll xmax = arr[i - 1].X, ymax = arr[i - 1].Y;
		for (int j = i; j > 0; j--) {
			ymax = max(ymax, arr[j-1].Y);
			dp[i] = min(dp[i], dp[j-1] + xmax * ymax);
		}
	}
	cout << dp[n] * 4;
}
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int SIZE = 3 * 1e5;
int n, arr[SIZE];
long long dp[SIZE][3];
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	dp[0][0] = abs(arr[0]); dp[0][1] = arr[0] * 2;
	for (int i = 1; i < n; i++) {
		dp[i][0] = dp[i - 1][0] + abs(arr[i]);
		dp[i][1] = max(dp[i - 1][1], dp[i - 1][0]) + arr[i] * 2;
		dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]) + abs(arr[i]);
	}
	cout << max({ dp[n - 1][0],dp[n - 1][1],dp[n - 1][2] });
}
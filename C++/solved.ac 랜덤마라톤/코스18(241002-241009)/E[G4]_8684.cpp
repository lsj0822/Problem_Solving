#include<iostream>
#include<algorithm>
using namespace std;
const long long MX = 1e18;
int n, g;
long long dp[1005];
pair<int, int> arr[10005];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> g;
	fill(&dp[1], &dp[g + 1], MX);
	for (int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;
	for (int i = 0; i < n; i++) {
		for (int j = g-1; j >= 0; j--) {
			for (int k = 1; k <= min(arr[i].first, g); k++) {
				if (j + k > g) break;
				dp[j + k] = min(dp[j + k], dp[j] + arr[i].second + k);
			}
		}
	}
	if (dp[g] == MX) cout << "NIE";
	else cout << dp[g];
}
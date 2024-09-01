#include<iostream>
#include<string>
using namespace std;
long long dp[105];
int seg[8] = { 0,0,1,7,4,2,0,8 };
int n;
int main() {
	fill(&dp[0], &dp[101], 1e15);
	dp[2] = 1; dp[3] = 7; dp[4] = 4; dp[5] = 2; dp[6] = 6; dp[7] = 8;
	for (int i = 8; i <= 100; i++) {
		for (int j = 2; j <= 7; j++) {
			dp[i] = min(dp[i], dp[i - j] * 10 + seg[j]);
		}
	}
	cin >> n;
	while (n--) {
		int k;
		cin >> k;
		cout << dp[k] << ' ';
		while (k > 0) {
			if (k % 2 == 1) {
				cout << 7;
				k -= 3;
			}
			else {
				cout << 1;
				k -= 2;
			}
		}
		cout << '\n';
	}
}
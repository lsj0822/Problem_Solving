#include<iostream>
using namespace std;
int seg[8] = { 0,0,1,7,4,5,9,8 }, dp[1000005], n;
int main() {
	cin >> n;
	for (int i = 2; i <= 7; i++) dp[i] = seg[i];
	for (int i = 4; i <= n; i++) {
		for (int j = 2; j <= 7; j++) {
			if (i - j < 2) break;
			dp[i] = max(dp[i], dp[i - j] + seg[j]);
		}
	}
	cout << dp[n];
}
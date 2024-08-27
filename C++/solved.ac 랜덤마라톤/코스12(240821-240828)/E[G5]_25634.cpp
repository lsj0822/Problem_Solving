#include<iostream>
#include<algorithm>
using namespace std;
int power[200005], bulb[200005][2], dp[200005][3], onpower = 0, offpower = 0, n;
//dp 0 :반전전 1 : 반전중 2 : 반전후
bool status;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> power[i];
	for (int i = 0; i < n; i++) {
		cin >> status;
		bulb[i][status] = power[i];
	}
	dp[0][0] = bulb[0][1]; dp[0][1] = bulb[0][0];
	for (int i = 1; i < n; i++) {
		dp[i][0] = dp[i - 1][0] + bulb[i][1];
		dp[i][1] = max(dp[i - 1][1], dp[i - 1][0]) + bulb[i][0];
		dp[i][2] = max(dp[i - 1][2], dp[i - 1][1]) + bulb[i][1];
	}
	cout << max(dp[n - 1][1], dp[n - 1][2]); //반전이 일어나고 있거나 일어남이 끝난 결과만 출력
}
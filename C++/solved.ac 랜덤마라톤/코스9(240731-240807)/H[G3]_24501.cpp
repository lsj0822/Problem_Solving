#include<iostream>
#include<string>
using namespace std;
const int DIV = 1'000'000'007;
int n, m;
long long dp[3005][3005], cnt[3005][3005][2], ans = 0;
string arr[3005];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	for (int i = 1; i <= n; i++) {
		int tcnt[2] = { 0,0 };
		for (int j = 0; j < m; j++) {
;			switch (arr[i][j]) {
			case 'E':
				tcnt[0]++;
				break;
			case 'M':
				tcnt[1]++;
				break;
			}
			for (int k = 0; k < 2; k++) cnt[i][j+1][k] = tcnt[k] + cnt[i - 1][j+1][k];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j - 1] == 'S') ans = (ans + cnt[i][j][0] * (cnt[n][m][1] - cnt[i - 1][m][1] - cnt[n][j - 1][1] + cnt[i - 1][j - 1][1]))%DIV;
		}
	}
	cout << ans;
}
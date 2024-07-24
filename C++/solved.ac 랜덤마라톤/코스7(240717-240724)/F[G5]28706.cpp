#include<iostream>
#include<algorithm>
using namespace std;
int t, n, v1, v2;
char op1, op2;
bool dp[200005][7];
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		fill(&dp[0][0], &dp[n+1][0], 0);
		dp[0][1] = 1;
		for (int i = 1; i <= n; i++) {
			cin >> op1 >> v1 >> op2 >> v2;
			switch (op1) {
			case '+':
				for (int j = 0; j < 7; j++) { 
					if (!dp[i - 1][j]) continue;
					dp[i][(j + v1) % 7] = 1; 
				}
				break;
			case '*':
				for (int j = 0; j < 7; j++) {
					if (!dp[i - 1][j]) continue;
					dp[i][(j * v1) % 7] = 1;
				}
				break;
			}
			switch (op2) {
			case '+':
				for (int j = 0; j < 7; j++) {
					if (!dp[i - 1][j]) continue;
					dp[i][(j + v2) % 7] = 1;
				}
				break;
			case '*':
				for (int j = 0; j < 7; j++) {
					if (!dp[i - 1][j]) continue;
					dp[i][(j * v2) % 7] = 1;
				}
				break;
			}
		}
		if (!dp[n][0]) cout << "UN";
		cout << "LUCKY\n";
	}
}
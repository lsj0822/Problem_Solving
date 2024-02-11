#include <bits/stdc++.h>

using namespace std;
int t, n;
int sticker[2][100005], ans[2][100005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		fill(&sticker[0][0], &sticker[1][100005], 0);
		fill(&ans[0][0], &ans[1][100005], 0);
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> sticker[i][j];
			}
		}
		for (int i : {0, 1}) {
			ans[i][0] = sticker[i][0];
			ans[i][1] = sticker[!i][0] + sticker[i][1];
		}
		for (int i = 2; i < n; i++) {
			for (int k : {0, 1}) {
				ans[k][i] = max({ ans[!k][i - 1], ans[1][i - 2], ans[0][i - 2] }) + sticker[k][i];
			}
		}
		cout << max(ans[0][n - 1], ans[1][n - 1]) << '\n';
	}
}
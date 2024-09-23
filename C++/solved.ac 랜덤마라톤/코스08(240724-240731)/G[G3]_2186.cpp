#include<iostream>
#include<string>
using namespace std;
string board[105], word;
int n, m, k, dp[105][105][85], ans = 0;
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) cin >> board[i];
	cin >> word;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == word[0]) dp[i][j][0] = 1;
		}
	}

	int wlen = (int)word.length();
	for (int w = 1; w < wlen; w++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] != word[w]) continue;
				for (int a = 1; a <= k; a++) {
					for (int dir = 0; dir < 4; dir++) {
						int px = i + a * dx[dir], py = j + a * dy[dir];
						if (px < 0 || px >= n || py < 0 || py >= m) continue;
						if (board[px][py] != word[w - 1]) continue;
						dp[i][j][w] += dp[px][py][w - 1];
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans += dp[i][j][wlen - 1];
		}
	}
	cout << ans;
}
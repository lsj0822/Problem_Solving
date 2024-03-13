#include <bits/stdc++.h>

using namespace std;
int n, m, pos[105][10005], board[105][10005], ans = 0;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		vector<int> vec;
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			vec.push_back(board[i][j]);
		}
		sort(vec.begin(), vec.end());
		for (int j = 0; j < n; j++) {
			pos[i][j] = lower_bound(vec.begin(), vec.end(), board[i][j]) - vec.begin();
		}
	}
	for (int i = 0; i < m - 1; i++) {
		for (int j = i + 1; j < m; j++) {
			bool res = true;
			for (int k = 0; k < n; k++) {
				if (pos[i][k] != pos[j][k]) {
					res = false;
					break;
				}
			}
			if (res) ans++;
		}
	}
	cout << ans;
}
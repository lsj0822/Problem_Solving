#include <bits/stdc++.h>
using namespace std;
int ground[2500], player[50][10], n, ans = -1, out, lidx, ridx, res, sq = 0, player_sq[10];
vector<int> turn;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> player[i][j];
		}
	}
	for (int i = 1; i <= 8; i++) turn.push_back(i);
	do {
		res = 0, sq = 0;
		memset(player_sq, 0, sizeof(player_sq));
		for (int t = 0; t < 3; t++) player_sq[t] = turn[t];
		player_sq[3] = 0;
		for (int t = 3; t < 8; t++) player_sq[t + 1] = turn[t];
		for (int i = 0; i < n; i++) {
			memset(ground, 0, sizeof(ground));
			out = 0, lidx = 0, ridx = 0;
			while (out < 3) {
				if (player[i][player_sq[sq]] == 0) out++;
				else {
					ground[ridx] = 1;
					ridx += player[i][player_sq[sq]];
					while (lidx + 3 < ridx) {
						res += ground[lidx];
						lidx++;
					}
				}
				sq = (sq + 1) % 9;
			}
		}
		ans = max(ans, res);
	} while (next_permutation(turn.begin(), turn.end()));
	cout << ans;
}
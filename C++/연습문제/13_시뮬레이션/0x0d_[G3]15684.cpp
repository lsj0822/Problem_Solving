#include<iostream>
using namespace std;
int ans = 4, n, m, h;
bool ladder[15][40], res;
bool ladder_check() {
	for (int i = 1; i <= n; i++) {
		int pos = i;
		for (int j = 1; j <= h; j++) {
			if (ladder[pos-1][j]) pos--;
			else if (ladder[pos][j]) pos++;
		}
		if (pos != i) return false;
	}
	return true;
}
bool ladder_valid(int x, int y) {
	if (ladder[x][y]) return false;
	if (ladder[x + 1][y]) return false;
	if (ladder[x - 1][y]) return false;
	return true;
}
void back_tracking(int dep) {
	if (dep >= ans) return;
	if (ladder_check()) {
		ans = dep;
		return;
	}
	if (dep + 1 >= ans) return;
	for (int j = 1; j < n; j++) {
		for (int i = 1; i <= h; i++) {
			if (ladder_valid(j, i)) {
				ladder[j][i] = 1;
				back_tracking(dep + 1);
				ladder[j][i] = 0;
				while (!ladder[j - 1][i] && !ladder[j + 1][i]) i++;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> h;
	fill(&ladder[0][0], &ladder[12][0], 0);
	while (m--) {
		int a, b;
		cin >> a >> b;
		ladder[b][a] = 1;
	}
	if (ladder_check()) {
		cout << 0;
		return 0;
	}
	back_tracking(0);
	if (ans == 4) ans = -1;
	cout << ans;
}
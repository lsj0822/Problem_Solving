#include <bits/stdc++.h>

using namespace std;
int r, c, t, arr[55][55], rf, cp[55][55], ans = 0;
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> r >> c >> t;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == -1) rf = i;
		}
	}
	while (t--) {
		//먼지확산
		memset(cp, 0, sizeof(cp));
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (arr[i][j]) {
					int remain = arr[i][j];
					for (int dir = 0; dir < 4; dir++) {
						int x = i + dx[dir], y = j + dy[dir];
						if (x < 0 || x >= r || y < 0 || y >= c || arr[x][y] == -1) continue;
						cp[x][y] += arr[i][j] / 5;
						remain -= arr[i][j] / 5;
					}
					cp[i][j] += remain;
				}
			}
		}
		copy(&cp[0][0], &cp[54][54]+1, &arr[0][0]);
		//공기순환
		for (int i = rf - 3; i >= 0; i--) arr[i + 1][0] = arr[i][0];
		for (int i = 1; i < c; i++) arr[0][i - 1] = arr[0][i];
		for (int i = 1; i < rf; i++) arr[i - 1][c - 1] = arr[i][c - 1];
		for (int i = c - 2; i >= 1; i--) arr[rf - 1][i + 1] = arr[rf - 1][i];
		arr[rf - 1][1] = 0;
		for (int i = rf + 2; i < r; i++) arr[i - 1][0] = arr[i][0];
		for (int i = 1; i < c; i++) arr[r - 1][i - 1] = arr[r - 1][i];
		for (int i = r - 2; i >= rf; i--) arr[i + 1][c - 1] = arr[i][c - 1];
		for (int i = c - 2; i >= 1; i--) arr[rf][i + 1] = arr[rf][i];
		arr[rf][1] = 0;
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			ans += arr[i][j];
		}
	}
	cout << ans+2;
}
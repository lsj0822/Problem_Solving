#include <iostream>
#define X first
#define Y second
 
using namespace std;
int n, m, r, c, d, board[51][51], vst[51][51], ans = 0;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int main() {
	cin >> n >> m >> r >> c >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j]) vst[i][j] = 1;
		}
	}

	while (true) {
		if (!vst[r][c]) {
			vst[r][c] = 1;
			ans++;
		}
		bool detect_dust = false;
		for (int dir = 0; dir < 4; dir++) {
			if (!vst[r + dx[dir]][c + dy[dir]]) detect_dust = true;
		}
		if (detect_dust) {
			for (int dir = 0; dir < 4; dir++) {
				d = (d + 3) % 4;
				if (!vst[r + dx[d]][c + dy[d]]) {
					r += dx[d];
					c += dy[d];
					break;
				}
			}
		}
		else {
			if (board[r - dx[d]][c - dy[d]]) break;
			else {
				r -= dx[d];
				c -= dy[d];
			}
		}
	}
	cout << ans;
}
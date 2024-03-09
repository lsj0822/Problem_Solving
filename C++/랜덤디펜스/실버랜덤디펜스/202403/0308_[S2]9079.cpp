#include <bits/stdc++.h>

using namespace std;

int t, board[3][3], ans = 10, vst[8];
void flip(int dir) {
	switch (dir) {
	case 0:
	case 1:
	case 2:
		for (int i = 0; i < 3; i++) {
			board[i][dir] = 1 - board[i][dir];
		}
		break;
	case 3:
	case 4:
	case 5:
		for (int i = 0; i < 3; i++) {
			board[dir - 3][i] = 1 - board[dir - 3][i];
		}
		break;
	case 6:
		for (int i = 0; i < 3; i++) board[i][i] = 1 - board[i][i];
		break;
	case 7:
		for (int i = 0; i < 3; i++) board[i][2 - i] = 1 - board[i][2 - i];
		break;
	}
}
void bt(int dep) {
	int bsum = 0;
	for (int i = 0; i < 9; i++) {
		bsum += board[i / 3][i % 3];
	}
	if (bsum == 0 || bsum == 9) {
		ans = min(ans, dep);
		return;
	}
	for (int i = 0; i < 8; i++) {
		if (vst[i]) continue;
		vst[i] = 1;
		flip(i);
		bt(dep + 1);
		flip(i);
		vst[i] = 0;
	}
}
int main() {
	cin >> t;
	while (t--) {
		ans = 10;
		memset(board, 0, sizeof(int) * 9);
		memset(vst, 0, sizeof(int) * 8);
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				char c;
				cin >> c;
				if (c == 'H') board[i][j] = 1;
				else board[i][j] = 0;
			}
		}
		bt(0);
		if (ans == 10) cout << -1;
		else cout << ans;
		cout << '\n';
	}
}
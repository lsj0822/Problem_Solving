#include<iostream>
#include<string>
using namespace std;
int t, ans, x, y, dx[4] = { -1,-1,1,1 }, dy[4] = { -1,1,-1,1 };
string board[10];
void back_tracking(int x, int y, int depth) {
	bool is_move = false;
	for (int dir = 0; dir < 4; dir++) {
		int ox = x + dx[dir], nx = x + 2 * dx[dir], oy = y + dy[dir], ny = y + 2 * dy[dir];
		if (ox < 0 || oy < 0 || nx < 0 || ny < 0 || ox >= 10 || oy >= 10 || nx >= 10 || ny >= 10) continue;
		if (board[ox][oy] == 'B' && board[nx][ny] == '#') {
			is_move = true;
			board[ox][oy] = '#'; board[nx][ny] = 'W'; board[x][y] = '#';
			back_tracking(nx, ny, depth + 1);
			board[ox][oy] = 'B'; board[nx][ny] = '#'; board[x][y] = 'W';
		}
	}
	if (!is_move) {
		ans = max(ans, depth);
		return;
	}
}

int main() {
	cin >> t;
	while (t--) {
		ans = 0;
		for (int i = 0; i < 10; i++) cin >> board[i];
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (board[i][j] == 'W') back_tracking(i, j, 0);
			}
		}
		cout << ans << '\n';
	}
}
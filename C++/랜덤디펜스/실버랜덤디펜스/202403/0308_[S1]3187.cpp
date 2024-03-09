#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
int n, m, sheep = 0, wolf = 0, vst[255][255];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };
string board[255];
queue<pair<int, int>>Q;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> board[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] != '#' && vst[i][j] == 0) {
				Q.push({ i,j });
				vst[i][j] = 1;
				int scnt = 0, wcnt = 0;
				while (!Q.empty()) {
					auto cur = Q.front(); Q.pop();
					int x = cur.X, y = cur.Y;
					if (board[x][y] == 'v') wcnt++;
					if (board[x][y] == 'k') scnt++;
					for (int dir = 0; dir < 4; dir++) {
						int nx = x + dx[dir], ny = y + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (vst[nx][ny] == 1 || board[nx][ny] == '#') continue;
						Q.push({ nx,ny });
						vst[nx][ny] = 1;
					}
				}
				if (scnt > wcnt) sheep += scnt;
				else wolf += wcnt;
			}
		}
	}
	cout << sheep << ' ' << wolf;
}
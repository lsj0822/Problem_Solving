#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int L, R, C, ex, ey, ez;
int dx[6] = { 0,0,1,-1,0,0 };
int dy[6] = { 0,0,0,0,1,-1 };
int dz[6] = { 1,-1,0,0,0,0 };
char board[35][35][35];
int vst[35][35][35];
queue < pair<int, pair<int, int>>> Q;

int main() {
	while (true) {
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0) break;
		bool flag = false;
		fill(&vst[0][0][0], &vst[34][34][34], -1);

		for (int z = 0; z < L; z++) {
			for (int r = 0; r < R; r++) {
				string str;
				cin >> str;
				for(int c = 0; c < C; c++){
					board[z][r][c] = str[c];
					if (board[z][r][c] == 'S') {
						Q.push({ z,{r,c} });
						vst[z][r][c] = 0;
					}
					if (board[z][r][c] == 'E') {
						ex = r; ey = c; ez = z;
					}
				}
			}
		}

		while (!Q.empty()) {
			auto cur = Q.front(); Q.pop();
			if (cur.X == ez && cur.Y.X == ex && cur.Y.Y == ey) {
				int result = vst[cur.X][cur.Y.X][cur.Y.Y];
				cout << "Escaped in " << result << " minute(s).\n";
				flag = true;
				break;
			}
			for (int dir = 0; dir < 6; dir++) {
				int nx = cur.Y.X + dx[dir];
				int ny = cur.Y.Y + dy[dir];
				int nz = cur.X + dz[dir];
				if (nz < 0 || nz >= L || nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
				if (vst[nz][nx][ny] != -1 || board[nz][nx][ny] == '#') continue;
				vst[nz][nx][ny] = vst[cur.X][cur.Y.X][cur.Y.Y] + 1;
				Q.push({ nz,{nx,ny} });
			}
		}
		if (!flag) cout << "Trapped!\n";
		while (!Q.empty()) Q.pop();

	}
}
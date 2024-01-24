#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int t, w, h, sx, sy;

int fire[1002][1002], path[1002][1002];
string maze[1002];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };

int main() {
	cin >> t;
	while (t--) {
		bool flag = false;
		cin >> w >> h;
		for (int i = 0; i < h; i++) {
			fill(fire[i], fire[i] + w, -1);
			fill(path[i], path[i] + w, -1);
		}
		for (int i = 0; i < h; i++) {
			cin >> maze[i];
		}
		queue<pair<int, int>> FQ;
		queue<pair<int, int>> SQ;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (maze[i][j] == '*') {
					FQ.push(make_pair(i, j));
					fire[i][j] = 0;
				}
				else if (maze[i][j] == '@') {
					sx = i;
					sy = j;
				}
			}
		}

		while (!FQ.empty()) {
			auto cur = FQ.front(); FQ.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
				if (maze[nx][ny] == '#' || fire[nx][ny] >= 0) continue;
				fire[nx][ny] = fire[cur.X][cur.Y] + 1;
				FQ.push(make_pair(nx, ny));
			}
		}

		path[sx][sy] = 0;
		SQ.push(make_pair(sx, sy));

		while (!SQ.empty() && !flag) {
			auto scur = SQ.front(); SQ.pop();
			int plen = path[scur.X][scur.Y];
			for (int dir = 0; dir < 4; dir++) {
				int nsx = scur.X + dx[dir];
				int nsy = scur.Y + dy[dir];
				if (nsx < 0 || nsx >= h || nsy < 0 || nsy >= w) {
					flag = true;
					cout << plen + 1 << '\n';
					break;
				}
				if (path[nsx][nsy] >= 0 || maze[nsx][nsy] == '#' || (fire[nsx][nsy] != -1 && fire[nsx][nsy] <= plen + 1)) continue;
				path[nsx][nsy] = plen + 1;
				SQ.push(make_pair(nsx, nsy));
			}
		}
		if(!flag) cout << "IMPOSSIBLE" << '\n';
	}
	
}
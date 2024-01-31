#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second

int n, m, jx, jy;

int fire[1002][1002], path[1002][1002];
string maze[1002];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		fill(fire[i], fire[i] + m, -1);
		fill(path[i], path[i] + m, -1);
	}
	for (int i = 0; i < n; i++) {
		cin >> maze[i];
	}
	queue<pair<int, int>> fq;
	queue<pair<int, int>> jq;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (maze[i][j] == 'f') {
				fq.push(make_pair(i, j));
				fire[i][j] = 0;
			}
			else if (maze[i][j] == 'j') {
				jx = i;
				jy = j;
			}
		}
	}

	while (!fq.empty()) {
		auto cur = fq.front(); fq.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.x + dx[dir];
			int ny = cur.y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (maze[nx][ny] == '#' || fire[nx][ny] >= 0) continue;
			fire[nx][ny] = fire[cur.x][cur.y] + 1;
			fq.push(make_pair(nx, ny));
		}
	}

	path[jx][jy] = 0;
	jq.push(make_pair(jx,jy));

	while (!jq.empty()) {
		auto jcur = jq.front(); jq.pop();
		int plen = path[jcur.x][jcur.y];
		for (int dir = 0; dir < 4; dir++) {
			int njx = jcur.x + dx[dir];
			int njy = jcur.y + dy[dir];
			if (njx < 0 || njx >= n || njy < 0 || njy >= m) {
				cout << plen + 1;
				return 0;
			}
			if (path[njx][njy] >= 0 || maze[njx][njy] == '#' ||(fire[njx][njy] != -1 && fire[njx][njy] <= plen + 1)) continue;
			path[njx][njy] = plen + 1;
			jq.push(make_pair(njx, njy));
		}
	}

	cout << "impossible";
}
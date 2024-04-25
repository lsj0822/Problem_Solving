#include <bits/stdc++.h>
using namespace std;
int n, island[105][105], idx = 1, vst[105][105], ans = 100005, crit;
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
queue<pair<int, int>> Q;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> island[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vst[i][j] || island[i][j] == 0) continue;
			island[i][j] = idx;
			vst[i][j] = 1;
			Q.push({ i,j });
			while (!Q.empty()) {
				auto cur = Q.front(); Q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.first + dx[dir], ny = cur.second + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (vst[nx][ny] || island[nx][ny]  == 0) continue;
					island[nx][ny] = idx;
					vst[nx][ny] = 1;
					Q.push({ nx,ny });
				}
			}
			idx++;
		}
	}
	fill(&vst[0][0], &vst[101][101], -1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (island[i][j] == 0) continue;
			vst[i][j] = 0;
			Q.push({ i,j });
		}
	}
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		int x = cur.first, y = cur.second;
		crit = island[x][y];
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir], ny = y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (island[nx][ny] == crit) continue;
			else if (island[nx][ny] != 0) {
				ans = min(ans, vst[x][y] + vst[nx][ny]);
			}
			else {
				island[nx][ny] = crit;
				vst[nx][ny] = vst[x][y] + 1;
				Q.push({ nx,ny });
			}
		}
	}
	cout << ans;
}
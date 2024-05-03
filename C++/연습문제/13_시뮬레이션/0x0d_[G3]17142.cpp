#include <bits/stdc++.h>
using namespace std;
const int MX = 1000005;
int lab[55][55], wall = 0, n, m, ans = MX, vst[2505], sq[11], dist[55][55];
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
vector<pair<int, int>> spot;
queue<pair<int, int>> Q;
int BFS() {
	int v_occupy = spot.size(), res = 0;
	fill(&dist[0][0], &dist[50][50], -1);
	for (int i = 0; i < m; i++) {
		Q.push(spot[sq[i]]);
		dist[spot[sq[i]].first][spot[sq[i]].second] = 0;
	}
	while (!Q.empty()) {
		if (v_occupy + wall == (n * n)) {
			while (!Q.empty()) Q.pop();
			return res;
		}
		auto cur = Q.front(); Q.pop();
		int x = cur.first, y = cur.second;
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir], ny = y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (dist[nx][ny] != -1) continue;
			if (lab[nx][ny] == 1) continue;
			dist[nx][ny] = dist[x][y] + 1;
			Q.push({ nx,ny });
			if(lab[nx][ny] == 0) v_occupy++;
			if (res < dist[nx][ny]) {
				res = dist[nx][ny];
				if (v_occupy + wall == (n * n)) {
					while (!Q.empty()) Q.pop();
					return res;
				}
			}
		}
	}
	return MX;
}
void BT(int dep, int srt) {
	int res;
	if (dep == m) {
		res = BFS();
		ans = min(ans, res);
		return;
	}
	int ss = spot.size();
	for (int i = srt; i < ss; i++) {
		if (vst[i]) continue;
		vst[i] = 1;
		sq[dep] = i;
		BT(dep + 1, i + 1);
		vst[i] = 0;
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> lab[i][j];
			if (lab[i][j] == 1) wall++;
			if (lab[i][j] == 2) spot.push_back({ i,j });
		}
	}
	BT(0, 0);
	if (ans == MX) ans = -1;
	cout << ans;
}
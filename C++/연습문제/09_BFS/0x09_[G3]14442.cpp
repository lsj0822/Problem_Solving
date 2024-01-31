#include<bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n, m, k;
int vst[1002][1002][11];
string board[1002];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
queue<pair<pair<int, int>, int>> Q;

int main() {
	fill(&vst[0][0][0], &vst[1001][1001][11], -1);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}
	Q.push({ {0,0},0 });
	vst[0][0][0] = 0;
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		int x = cur.X.X; int y = cur.X.Y; int layer = cur.Y;
		if (x == n - 1 && y == m - 1) {
			cout << vst[x][y][layer] + 1;
			return 0;
		}
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir]; int ny = y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] == '1' && layer < k && vst[nx][ny][layer-1] == -1) {
				vst[nx][ny][layer+1] = vst[x][y][layer] + 1;
				Q.push({ {nx,ny}, layer+1});
			}
			if (board[nx][ny] == '0' && vst[nx][ny][layer] == -1) {
				vst[nx][ny][layer] = vst[x][y][layer] + 1;
				Q.push({ {nx,ny}, layer });
			}
		}
	}
	cout << -1;
}
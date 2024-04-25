#include <iostream>
#include <string>
#include <queue>
#define X first
#define Y second
using namespace std;
int n, m, dist[55][55][64];
char maze[55][55];
int dx[4] = { -1,1,0,0 }, dy[4] = {0,0,-1,1};
queue<pair<pair<int, int>, int>> Q;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	fill(&dist[0][0][0], &dist[54][0][0], -1);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			maze[i][j] = c;
			if (c == '0') {
				Q.push({ {i,j},0 });
				dist[i][j][0] = 0;
			}
		}
	}
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		int x = cur.X.X, y = cur.X.Y;
		int k = cur.Y;
		if (maze[x][y] == '1') {
			cout << dist[x][y][k];
			return 0;
		}
		for (int dir = 0; dir < 4; dir++) {
			int nk = k;
			int nx = x + dx[dir], ny = y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (dist[nx][ny][k] != -1) continue;
			if (maze[nx][ny] == '#') continue;
			if (maze[nx][ny] >= 'A' && maze[nx][ny] <= 'F') {
				if (!(k & (1 << (maze[nx][ny] - 'A')))) continue;
			}
			if (maze[nx][ny] >= 'a' && maze[nx][ny] <= 'f') {
				if (!(nk & (1 << (maze[nx][ny] - 'a')))) nk += (1 << (maze[nx][ny] - 'a'));
			}
			dist[nx][ny][nk] = dist[x][y][k] + 1;
			Q.push({ {nx,ny},nk });
		}
	}
	cout << -1;
	return 0;
}
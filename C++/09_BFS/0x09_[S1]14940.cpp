#include <bits/stdc++.h>
#define X first 
#define Y second 
using namespace std;

int n, m;
int board[1002][1002], dist[1002][1002];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
queue<pair<int, int>> Q;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) fill(dist[i], dist[i] + m, -1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int k;
			cin >> k;
			board[i][j] = k;
			if (k == 2) {
				Q.push({ i,j });
				dist[i][j] = 0;
			}
			if (k == 0) {
				dist[i][j] = 0;
			}
		}
	}

	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (dist[nx][ny] != -1 || !board[nx][ny]) continue;
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			Q.push({ nx,ny });
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << dist[i][j] << " ";
		}
		cout << '\n';
	}
}
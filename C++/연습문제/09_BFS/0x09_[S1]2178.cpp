#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int brd[102][102];
int dist[102][102];
int n,m;
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			brd[i][j] = static_cast<int>(str[j]-'0');
			dist[i][j] = -1;
		}
	}
	queue < pair<int, int>> Q;
	Q.push(make_pair(0, 0));
	dist[0][0] = 0;
	while (!Q.empty()) {
		pair<int, int> cur = Q.front();
		Q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (brd[nx][ny] && dist[nx][ny] == -1) {
				dist[nx][ny] = dist[cur.X][cur.Y] + 1;
				Q.push(make_pair(nx, ny));
			}
		}
	}

	cout << dist[n - 1][m - 1] + 1;
}

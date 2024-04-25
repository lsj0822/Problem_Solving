#include <bits/stdc++.h>
using namespace std;
const int MX = 1000005;
int board[10][10][10], maze[10][10][10], ans = MX, dist[10][10][10], status[10], result;
int dx[6] = { 1,-1,0,0,0,0 }, dy[6] = { 0,0,-1,1,0,0 }, dz[6] = { 0,0,0,0,-1,1 };
queue<tuple<int, int, int>> Q;
vector<int> v;
void rotate(int f) {
	status[f] = (status[f] + 1) % 4;
	int tmp[6][6];
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			tmp[i][j] = board[f][j][4 - i];
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			board[f][i][j] = tmp[i][j];
		}
	}
	if (status[f] == 0) rotate(f + 1);
}
int BFS() {
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		int z = get<0>(cur), x = get<1>(cur), y = get<2>(cur);
		if (z == 4 && x == 4 && y == 4) return dist[z][x][y];
		for (int dir = 0; dir < 6; dir++) {
			int nx = x + dx[dir], ny = y + dy[dir], nz = z + dz[dir];
			if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || nz < 0 || nz >= 5) continue;
			if (dist[nz][nx][ny] != -1) continue;
			if (maze[nz][nx][ny] == 0) continue;
			dist[nz][nx][ny] = dist[z][x][y] + 1;
			Q.push(make_tuple(nz, nx, ny));
		}
	}
	return MX;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < 5; i++) v.push_back(i);
	for (int z = 0; z < 5; z++) {
		for (int x = 0; x < 5; x++) {
			for (int y = 0; y < 5; y++) {
				cin >> board[z][x][y];
			}
		}
	}
	do {
		for (int i = 0; i < 1024; i++) {
			fill(&dist[0][0][0], &dist[5][5][5], -1);
			dist[0][0][0] = 0;
			while (!Q.empty()) Q.pop();
			for (int z = 0; z < 5; z++) {
				for (int x = 0; x < 5; x++) {
					for (int y = 0; y < 5; y++) {
						maze[z][x][y] = board[v[z]][x][y];
					}
				}
			}
			if (maze[0][0][0] == 1)Q.push(make_tuple(0, 0, 0));
			result = BFS();
			ans = min(result, ans);
			rotate(0);
		}
	} while (next_permutation(v.begin(), v.end())); 
	if (ans == MX) ans = -1;
	cout << ans;
}
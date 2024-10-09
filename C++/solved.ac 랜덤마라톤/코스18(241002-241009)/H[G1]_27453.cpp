#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<tuple>
using namespace std;
char arr[1005][1005];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };
int n, m, k;
bool vst[1005][1005][4];
pair<int, int> goal;
queue<tuple<pair<int, int>, pair<int, int>, int, int>> Q;
int curse(int x, int y) {
	if (arr[x][y] == 'S' || (x == -1 && y == -1)) return 0;
	return arr[x][y] - '0';
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'S') {
				for (int dir = 0; dir < 4; dir++) vst[i][j][dir] = 1;
				Q.push({ { -1,-1 }, {i,j},-3, 0 });
			}
			if (arr[i][j] == 'H') goal = { i,j };
		}	
	}
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		int px, py, cx, cy, prevdir, prevdist;
		tie(px, py) = get<0>(cur); tie(cx, cy) = get<1>(cur);
		prevdir = get<2>(cur); prevdist = get<3>(cur);
		for (int dir = 0; dir < 4; dir++) {
			if (abs(prevdir - dir) == 2) continue;
			int nx = cx + dx[dir], ny = cy + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (arr[nx][ny] == 'X') continue;
			if (nx == goal.first && ny == goal.second) {
				cout << prevdist + 1;
				return 0;
			}
			int cursesum = curse(px, py) + curse(cx, cy) + curse(nx, ny);
			if (cursesum > k) continue;
			if (vst[nx][ny][dir]) continue;
			vst[nx][ny][dir] = 1;
			Q.push({ {cx,cy},{nx,ny}, dir, prevdist + 1 });
		}
	}
	cout << -1;
}
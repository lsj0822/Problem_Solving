#include<iostream>
#include<queue>
#define X first
#define Y second

using namespace std;
int w,h,k;
int board[301][301], vst[301][301][31];
int hdx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int hdy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
queue<pair<pair<int, int>,int>> Q;
int main() {
	cin >> k >> w >> h;
	for (int x = 0; x < h; x++) {
		for (int y = 0; y < w; y++) {
			cin >> board[x][y];
		}
	}
	Q.push({ { 0,0 },0 });
	vst[0][0][0] = 1;
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		if (cur.X.X == h - 1 && cur.X.Y == w - 1) {
			cout << vst[cur.X.X][cur.X.Y][cur.Y] - 1;
			return 0;
		}
		if (cur.Y < k) {
			for (int dir = 0; dir < 8; dir++) {
				int nx = cur.X.X + hdx[dir];
				int ny = cur.X.Y + hdy[dir];
				if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
				if (!vst[nx][ny][cur.Y + 1] && !board[nx][ny]) {
					vst[nx][ny][cur.Y + 1] = vst[cur.X.X][cur.X.Y][cur.Y] + 1;
					Q.push({ { nx,ny },cur.Y + 1 });
				}	
			}
		}
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X.X + dx[dir];
			int ny = cur.X.Y + dy[dir];
			if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
			if (!vst[nx][ny][cur.Y] && !board[nx][ny]) {
				vst[nx][ny][cur.Y] = vst[cur.X.X][cur.X.Y][cur.Y] + 1;
				Q.push({ { nx,ny },cur.Y });
			}
		}
	}
	cout << -1;
}
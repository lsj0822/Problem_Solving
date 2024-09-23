#include<iostream>
#include<queue>
using namespace std;
int n, m, board[705][705], ans = 0;
bool vst[705][705] = { false, };
int dx[8] = { 0,-1,-1,-1,0,1,1,1 }, dy[8] = {-1,-1,0,1,1,1,0,-1 };
bool BFS(int x, int y) {
	bool not_high = 1;
	queue<pair<int, int>> q;
	q.push({ x,y });
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 8; dir++) {
			int nx = cur.first + dx[dir], ny = cur.second + dy[dir];
			if ( nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] > board[cur.first][cur.second]) not_high = 0;
			if (board[nx][ny] != board[cur.first][cur.second]) continue;
			if (vst[nx][ny]) continue;
			vst[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}
	return not_high;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vst[i][j]) continue;
			ans+= BFS(i, j);
		}
	}
	cout << ans;
}
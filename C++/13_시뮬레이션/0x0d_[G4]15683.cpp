#include<iostream>
#define X first
#define Y second

using namespace std;

int n, m, idx = 0;
int board[9][9], vst[9][9], sqmin = 65;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
pair<pair<int, int>, int> CCTV[10];

bool check_board(int a, int b) {
	return a >= 0 && a < n && b >= 0 && b < m && board[a][b] != 6;
}
void bt(int dep) {
	if (dep == idx) {
		int res = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				res += (vst[i][j] == 0);
			}
		}
		sqmin = min(sqmin, res);
	}
	else {
		auto cur = CCTV[dep];
		switch (cur.Y) {
		case 1:
			for (int i = 0; i < 4; i++) {
				int nx = cur.X.X;
				int ny = cur.X.Y;
				while (check_board(nx,ny)) {
					vst[nx][ny] += 1;
					nx += dx[i];
					ny += dy[i];
				}
				bt(dep + 1);
				nx = cur.X.X;
				ny = cur.X.Y;
				while (check_board(nx, ny)) {
					vst[nx][ny] -= 1;
					nx += dx[i];
					ny += dy[i];
				}
			}
			break;
		case 2:
			for (int i = 0; i < 2; i++) {
				int nx1 = cur.X.X, nx2 = cur.X.X;
				int ny1 = cur.X.Y, ny2 = cur.X.Y;
				while (check_board(nx1, ny1)) {
					vst[nx1][ny1] += 1;
					nx1 += dx[i];
					ny1 += dy[i];
				}
				while (check_board(nx2, ny2)) {
					vst[nx2][ny2] += 1;
					nx2 += dx[i + 2];
					ny2 += dy[i + 2];
				}
				bt(dep + 1);
				nx1 = nx2 = cur.X.X;
				ny1 = ny2 = cur.X.Y;
				while (check_board(nx1, ny1)) {
					vst[nx1][ny1] -= 1;
					nx1 += dx[i];
					ny1 += dy[i];
				}
				while (check_board(nx2, ny2)) {
					vst[nx2][ny2] -= 1;
					nx2 += dx[i+2];
					ny2 += dy[i+2];
				}
			}
			break;
		case 3:
			for (int i = 0; i < 4; i++) {
				int nx1 = cur.X.X, nx2 = cur.X.X;
				int ny1 = cur.X.Y, ny2 = cur.X.Y;
				while (check_board(nx1, ny1)) {
					vst[nx1][ny1] += 1;
					nx1 += dx[i];
					ny1 += dy[i];
				}
				while (check_board(nx2, ny2)) {
					vst[nx2][ny2] += 1;
					nx2 += dx[(i+1)%4];
					ny2 += dy[(i+1)%4];
				}
				bt(dep + 1);
				nx1 = nx2 = cur.X.X;
				ny1 = ny2 = cur.X.Y;
				while (check_board(nx1, ny1)) {
					vst[nx1][ny1] -= 1;
					nx1 += dx[i];
					ny1 += dy[i];
				}
				while (check_board(nx2, ny2)) {
					vst[nx2][ny2] -= 1;
					nx2 += dx[(i+1)%4];
					ny2 += dy[(i+1)%4];
				}
			}
			break;
		case 4:
			for (int i = 0; i < 4; i++) {
				int nx1 = cur.X.X, nx2 = cur.X.X, nx3 = cur.X.X;
				int ny1 = cur.X.Y, ny2 = cur.X.Y, ny3 = cur.X.Y;
				while (check_board(nx1, ny1)) {
					vst[nx1][ny1] += 1;
					nx1 += dx[i];
					ny1 += dy[i];
				}
				while (check_board(nx2, ny2)) {
					vst[nx2][ny2] += 1;
					nx2 += dx[(i+1)%4];
					ny2 += dy[(i+1)%4];
				}
				while (check_board(nx3, ny3)) {
					vst[nx3][ny3] += 1;
					nx3 += dx[(i+2)%4];
					ny3 += dy[(i+2)%4];
				}
				bt(dep + 1);
				nx1 = nx2 = nx3 = cur.X.X;
				ny1 = ny2 = ny3 = cur.X.Y;
				while (check_board(nx1, ny1)) {
					vst[nx1][ny1] -= 1;
					nx1 += dx[i];
					ny1 += dy[i];
				}
				while (check_board(nx2, ny2)) {
					vst[nx2][ny2] -= 1;
					nx2 += dx[(i+1)%4];
					ny2 += dy[(i+1)%4];
				}
				while (check_board(nx3, ny3)) {
					vst[nx3][ny3] -= 1;
					nx3 += dx[(i+2)%4];
					ny3 += dy[(i+2)%4];
				}
			}
			break;
		case 5:
			for (int i = 0; i < 4; i++) {
				int nx = cur.X.X;
				int ny = cur.X.Y;
				while (check_board(nx, ny)) {
					vst[nx][ny] += 1;
					nx += dx[i];
					ny += dy[i];
				}
			}
			bt(dep + 1);
			for(int i = 0; i < 4; i++){
				int nx = cur.X.X;
				int ny = cur.X.Y;
				while (check_board(nx, ny)) {
					vst[nx][ny] -= 1;
					nx += dx[i];
					ny += dy[i];
				}
			}
			break;
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int k;
			cin >> k;
			board[i][j] = k;
			if (k >= 1 && k < 6) {
				CCTV[idx] = { {i,j},k };
				idx++;
			}
			if (k == 6) vst[i][j] = 1;
		}
	}
	bt(0);
	cout << sqmin;
}
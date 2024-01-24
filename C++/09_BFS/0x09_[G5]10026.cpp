#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n, result = 0, dal_result = 0;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int vst[102][102];
char board[102][102];
queue<pair<int, int>> Q;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int c = 0; c < n; c++) {
			board[i][c] = str[c];
		}
	}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (vst[i][j]) continue;
				Q.push({ i,j });
				char ck = board[i][j];
				vst[i][j] = 1;
				while (!Q.empty()) {
					auto cur = Q.front(); Q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
						if (vst[nx][ny] || board[nx][ny] != ck) continue;
						Q.push({ nx, ny });
						vst[nx][ny] = 1;
					}
				}
				result++;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] == 'G') board[i][j] = 'R';
				vst[i][j] = 0;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (vst[i][j]) continue;
				Q.push({ i,j });
				char ck = board[i][j];
				vst[i][j] = 1;
				while (!Q.empty()) {
					auto cur = Q.front(); Q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
						if (vst[nx][ny] || board[nx][ny] != ck) continue;
						Q.push({ nx, ny });
						vst[nx][ny] = 1;
					}
				}
				dal_result++;
			}
		}

		cout << result << " " << dal_result;
}

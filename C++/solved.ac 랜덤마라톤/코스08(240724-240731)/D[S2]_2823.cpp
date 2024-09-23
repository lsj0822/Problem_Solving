#include<iostream>
#include<string>
using namespace std;
int n, m;
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
string board[12];
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> board[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'X') continue;
			int cnt = 0;
			for (int dir = 0; dir < 4; dir++) {
				int nx = i + dx[dir], ny = j + dy[dir];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (board[nx][ny] == '.') cnt++;
			}
			if (cnt <= 1) {
				cout << 1;
				return 0;
			}
		}
	}
	cout << 0;
}
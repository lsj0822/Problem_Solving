#include<iostream>
#include<algorithm>
using namespace std;
int n, board[22][22], favor[405][4], dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 }, ans = 0, input_case;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	input_case = n * n;
	while(input_case--) {
		pair<int, int> adj[22][22]; //first : 호감, second : 비어있음
		int k, adjmax = 0;
		pair<int, int> favormax = { 0,0 };
		cin >> k;
		for (int j = 0; j < 4; j++) cin >> favor[k][j];
		for (int x = 1; x <= n; x++) {
			for (int y = 1; y <= n; y++) {
				if (board[x][y] != 0) continue;
				for (int dir = 0; dir < 4; dir++) {
					int nx = x + dx[dir], ny = y + dy[dir];
					if (nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
					if (board[nx][ny] == 0) adj[x][y].second++;
					else {
						for (int l = 0; l < 4; l++) {
							if (board[nx][ny] == favor[k][l]) adj[x][y].first++;
						}
					}
				}
				if (adj[x][y].first > favormax.first) favormax = { adj[x][y].first, 1 };
				else if (adj[x][y].first == favormax.first) favormax.second++;
			}
		}
		if (favormax.second == 1) {
			bool find = false;
			for (int x = 1; x <= n; x++) {
				if (find) break;
				for (int y = 1; y <= n; y++) {
					if (board[x][y] != 0) continue;
					if (adj[x][y].first == favormax.first) {
						board[x][y] = k;
						find = true;
						break;
					}
				}
			}
		}
		else {
			for (int x = 1; x <= n;x++) {
				for (int y = 1; y <= n; y++) {
					if (adj[x][y].first == favormax.first) adjmax = max(adjmax, adj[x][y].second);
				}
			}
			bool find = false;
			for (int x = 1; x <= n; x++) {
				if (find) break;
				for (int y = 1; y <= n; y++) {
					if (board[x][y] != 0) continue;
					if (adj[x][y].second == adjmax && adj[x][y].first == favormax.first) {
						board[x][y] = k;
						find = true;
						break;
					}
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int tmp = 0;
			for (int dir = 0; dir < 4; dir++) {
				int nx = i + dx[dir], ny = j + dy[dir];
				if (nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
				for (int l = 0; l < 4; l++) {
					if (board[nx][ny] == favor[board[i][j]][l]) {
						if (tmp == 0) tmp++;
						else tmp *= 10;
					}
				}
			}
			ans += tmp;
		}
	}
	cout << ans;
}